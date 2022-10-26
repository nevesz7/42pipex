/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:25:15 by rarobert          #+#    #+#             */
/*   Updated: 2022/04/13 14:24:27 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse_copy(char *dest, char *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*char_dest;
	char	*char_src;
	char	*answer;
	long	long_n;

	long_n = n;
	char_dest = (char *)dest;
	answer = (char *)dest;
	char_src = (char *)src;
	if (char_src > char_dest)
	{
		while (long_n > (char_dest - answer))
		{
			*char_dest = *char_src;
			char_dest++;
			char_src++;
		}
	}
	else
		reverse_copy(char_dest, char_src, n);
	return (dest);
}

static void	reverse_copy(char *dest, char *src, size_t n)
{
	size_t	x;

	x = n;
	while (x > 0)
	{
		dest++;
		src++;
		x--;
	}
	while (x < n)
	{
		dest--;
		src--;
		*dest = *src;
		x++;
	}
}
