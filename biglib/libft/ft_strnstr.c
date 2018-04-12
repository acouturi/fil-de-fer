/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:17:26 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:56:33 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_strnstr(const char *source, const char *mot, size_t n)
{
	size_t	len;

	if (!(*mot))
		return ((char *)source);
	len = ft_strlen(mot);
	while (*source && n-- >= len)
	{
		if (*source == *mot && ft_memcmp(source, mot, len) == 0)
			return ((char *)source);
		source++;
	}
	return (NULL);
}
