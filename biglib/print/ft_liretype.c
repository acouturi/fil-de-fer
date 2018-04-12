/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liretype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:15:05 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:43:10 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"
#include "../lib/libft.h"

void	ft_liretype(t_remp *stru)
{
	if (*stru->format == 'h')
		stru->longueur = *(stru->format + 1) == 'h' ? hh : h;
	else if (*stru->format == 'l')
		stru->longueur = *(stru->format + 1) == 'l' ? ll : l;
	else if (*stru->format == 'z')
		stru->longueur = z;
	else if (*stru->format == 'j')
		stru->longueur = j;
	stru->format++;
	while (ft_strchrc("hlzj", *stru->format))
		stru->format++;
}
