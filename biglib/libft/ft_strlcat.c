/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:34:24 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:47:31 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen(dest);
	lensrc = ft_strlen(src);
	i = 0;
	if (size < lendst)
		return (lensrc + size);
	if (size == 0)
		return (0);
	while (lendst + i < size - 1 && src[i])
	{
		dest[lendst + i] = src[i];
		i++;
	}
	dest[lendst + i] = '\0';
	return (lendst + lensrc);
}
