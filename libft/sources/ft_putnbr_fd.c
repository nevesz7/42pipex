/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:28:31 by rarobert          #+#    #+#             */
/*   Updated: 2022/04/18 13:17:14 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_negative(int n, int fd)
{
	if (n < 0)
	{
		write (fd, "-", 1);
		n = n * (-1);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (!(n == -2147483648))
	{
		n = ft_check_negative(n, fd);
		if (n < 10)
		{
			c = n + 48;
			write (fd, &c, 1);
		}
		else
		{
			ft_putnbr_fd((n / 10), fd);
			c = (n % 10) + 48;
			write (fd, &c, 1);
		}
	}
	else
		write (fd, "-2147483648", 11);
}
