/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:33:17 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:43:51 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		return (0);
	ft_bzero(ret, size);
	return (ret);
}
