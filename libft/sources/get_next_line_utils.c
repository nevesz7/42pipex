/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:40:27 by rarobert          #+#    #+#             */
/*   Updated: 2022/10/08 11:38:01 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str [i])
		i++;
	return (i);
}

char	get_next_char(int fd)
{
	ssize_t	x;
	char	c;

	c = 0;
	x = read(fd, &c, 1);
	if (x > 0)
		return (c);
	return (0);
}

t_list_gnl	*ft_lstnew_gnl(void)
{
	t_list_gnl	*node;

	node = (t_list_gnl *)malloc(sizeof(t_list_gnl));
	if (!node)
		return (NULL);
	node->next = NULL;
	return (node);
}
