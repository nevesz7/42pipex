/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:04:04 by rarobert          #+#    #+#             */
/*   Updated: 2022/04/22 05:04:48 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	little_len = ft_strlen(little);
	if (!little)
		return (NULL);
	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[i] && i <= len)
	{
		if (i + little_len > len)
			return (NULL);
		if (ft_strncmp(&big[i], &little[0], little_len) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
