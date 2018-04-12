/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:48:30 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:44:17 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *s1;
	char *s2;

	s1 = (char*)dest;
	s2 = (char*)src;
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	while (n-- > 0)
		s1[n] = s2[n];
	return (dest);
}
