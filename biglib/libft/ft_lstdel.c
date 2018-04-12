/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:17:11 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:43:17 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *suiv;

	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		suiv = *alst;
		free(*alst);
		*alst = suiv->next;
	}
}
