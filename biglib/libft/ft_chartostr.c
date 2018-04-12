/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:18:14 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:40:19 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_chartostr(char c)
{
	char	*str;

	if (!(str = malloc(2)))
		return (NULL);
	str[0] = c;
	str[1] = 0;
	return (str);
}
