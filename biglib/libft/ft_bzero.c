/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:48:50 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:39:40 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp;

	tmp = s;
	while (0 < n--)
		*tmp++ = 0;
}