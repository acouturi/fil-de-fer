/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:01:13 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:48:49 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = malloc(++size);
	if (!new)
		return (0);
	while (size-- > 0)
		new[size] = 0;
	return (new);
}
