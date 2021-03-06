/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:52:57 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:56:44 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_strrev(char *str)
{
	char	tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i <= len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i];
		str[len - i++] = tmp;
	}
	return (str);
}
