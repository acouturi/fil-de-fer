/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:05:50 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:45:53 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	tmp;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp = -n;
	}
	else
		tmp = n;
	if (tmp / 10)
		ft_putnbr_fd(tmp / 10, fd);
	ft_putchar_fd('0' + tmp % 10, fd);
}
