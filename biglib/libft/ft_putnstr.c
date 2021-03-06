/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:14:07 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:46:15 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	ft_putnstr(const char *s, int n)
{
	int i;

	if (s)
	{
		i = ft_strlen(s);
		write(1, s, i < n ? i : n);
	}
}
