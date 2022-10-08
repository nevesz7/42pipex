/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:03:55 by rarobert          #+#    #+#             */
/*   Updated: 2022/05/13 21:40:52 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dst);
	if (len_dest > size)
		len_dest = size + 1;
	i = 0;
	while (src[i] && (i + len_dest + 1) < size)
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	if (size < len_dest)
		return (size + len_src);
	dst[i + len_dest] = '\0';
	return (len_dest + len_src);
}
