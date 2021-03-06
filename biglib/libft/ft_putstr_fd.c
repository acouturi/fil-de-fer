/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:38:04 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:46:22 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i])
			ft_putchar_fd(s[i++], fd);
	}
}
