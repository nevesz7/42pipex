/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:37:59 by rarobert          #+#    #+#             */
/*   Updated: 2022/04/20 19:01:22 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copy;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	copy = *lst;
	copy = ft_lstlast(*lst);
	copy->next = new;
}
