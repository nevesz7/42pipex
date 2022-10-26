/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:03:53 by rarobert          #+#    #+#             */
/*   Updated: 2022/04/13 15:29:09 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	char	*aux;
	size_t	i;

	i = ft_strlen(src);
	aux = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i++])
		aux[i - 1] = src[i - 1];
	aux[i - 1] = src[i - 1];
	if (aux != NULL)
		return (aux);
	else
		return (NULL);
}
