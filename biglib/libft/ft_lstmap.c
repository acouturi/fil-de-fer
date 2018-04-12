/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:51:30 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:43:36 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *start;
	t_list *current;
	t_list *mem;

	if (!lst)
		return (NULL);
	mem = f(lst);
	start = mem;
	current = lst->next;
	while (current)
	{
		mem->next = f(current);
		mem = mem->next;
		current = current->next;
	}
	return (start);
}
