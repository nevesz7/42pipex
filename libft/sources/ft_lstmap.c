/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:06:20 by rarobert          #+#    #+#             */
/*   Updated: 2022/05/01 13:08:28 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*f_list;
	t_list	*f_node;

	f_list = (t_list *)malloc(sizeof(t_list));
	if (!f_list || !lst)
		return (NULL);
	f_list->content = (*f)(lst->content);
	f_list->next = NULL;
	lst = lst->next;
	while (lst)
	{
		f_node = ft_lstnew((*f)(lst->content));
		if (!(f_node))
		{
			ft_lstclear(&f_list, del);
			return (NULL);
		}
		ft_lstadd_back(&f_list, f_node);
		lst = lst->next;
	}
	return (f_list);
}
