/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:05:07 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:44:07 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = dest;
	s2 = (void*)src;
	if (n == 0)
		return (dest);
	while (0 < n--)
		*s1++ = *s2++;
	return (dest);
}
