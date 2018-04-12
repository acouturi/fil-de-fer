/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:16:15 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:48:20 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	char	*tab;
	int		length;

	if (!s)
		return (0);
	length = ft_strlen(s);
	tab = (char*)malloc(length + 1);
	if (!tab)
		return (0);
	i = 0;
	while (i < length)
	{
		tab[i] = f(s[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
