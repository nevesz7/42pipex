/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:24:34 by rarobert          #+#    #+#             */
/*   Updated: 2022/10/08 11:38:22 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int nb)
{
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = nb * (-1);
	}
	return (nb);
}

int	call_intelligence(int nb)
{
	char	c;
	int		printed;

	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	printed = 0;
	if (nb < 0)
		printed++;
	nb = check(nb);
	if (nb < 10)
	{
		c = nb + 48;
		write (1, &c, 1);
	}
	else
	{
		printed += call_intelligence(nb / 10);
		c = (nb % 10) + 48;
		write (1, &c, 1);
	}
	return (printed + 1);
}

int	call_unintelligence(unsigned int nb)
{
	char	c;
	int		printed;

	printed = 0;
	if (nb < 10)
	{
		c = nb + 48;
		write (1, &c, 1);
	}
	else
	{
		printed += call_unintelligence(nb / 10);
		c = (nb % 10) + 48;
		write (1, &c, 1);
	}
	return (printed + 1);
}

int	call_professor(unsigned int nb, char c)
{
	int		printed;
	char	*hex_tab;

	printed = 0;
	if (c == 'X')
		hex_tab = "0123456789ABCDEF";
	else
		hex_tab = "0123456789abcdef";
	if (nb < 16)
		write (1, &hex_tab[nb], 1);
	else
	{
		printed += call_professor((nb / 16), c);
		write (1, &hex_tab[nb % 16], 1);
	}
	return (printed + 1);
}

int	call_poncho(unsigned long long int nb)
{
	int		printed;
	char	*hex_tab;

	printed = 0;
	if (nb == 0)
		return (call_stacy("(nil)"));
	hex_tab = "0123456789abcdef";
	if (nb < 16)
	{
		write (1, "0x", 2);
		printed += 2;
		write (1, &hex_tab[nb], 1);
	}
	else
	{
		printed += call_poncho(nb / 16);
		write (1, &hex_tab[nb % 16], 1);
	}
	return (printed + 1);
}
