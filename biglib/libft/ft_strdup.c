/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:17:32 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:47:07 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*news;
	int		i;

	len = ft_strlen(s);
	news = (char*)malloc((len + 1) * sizeof(char));
	if (news == 0)
		return (0);
	i = 0;
	while (s && s[i])
	{
		news[i] = s[i];
		i++;
	}
	news[i] = 0;
	return (news);
}
