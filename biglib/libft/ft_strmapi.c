/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:16:15 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:48:26 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
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
		tab[i] = f(i, s[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
