/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:30:47 by acouturi          #+#    #+#             */
/*   Updated: 2018/03/07 15:32:53 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_strjoinfree(char *s1, const char *s2)
{
	char	*tab;
	int		len1;
	int		len2;
	int		i;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tab = (char*)malloc(len1 + len2 + 1);
	if (!tab)
		return (0);
	i = -1;
	while (++i < len1)
		tab[i] = s1[i];
	i = 0;
	while (i < len2)
	{
		tab[i + len1] = s2[i];
		i++;
	}
	tab[i + len1] = 0;
	free(s1);
	return (tab);
}
