/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:37:27 by rarobert          #+#    #+#             */
/*   Updated: 2022/05/06 02:16:28 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_itoa_len(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_get_itoa_len(n);
	itoa = malloc(i + 1);
	if (!itoa)
		return (NULL);
	itoa[i] = '\0';
	if (n < 0)
	{
		itoa[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		i--;
		itoa[i] = (n % 10) + 48;
		n = n / 10;
	}
	return (itoa);
}
