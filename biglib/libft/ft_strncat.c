/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:07:31 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:48:31 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	size_t	mem;

	i = 0;
	while (dest[i])
		i++;
	mem = 0;
	while (src[mem] && mem < n)
	{
		dest[i + mem] = src[mem];
		mem++;
	}
	dest[i + mem++] = 0;
	return (dest);
}
