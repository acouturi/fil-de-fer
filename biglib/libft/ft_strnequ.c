/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:18:44 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:48:43 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	if (!(s1 && s2))
		return (0);
	while ((s1[i] != 0 || s2[i] != 0) && n-- > 0)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
