/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 07:09:17 by rarobert          #+#    #+#             */
/*   Updated: 2022/10/08 11:38:13 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	call_charlie(int c)
{
	write(1, &c, 1);
	return (1);
}

int	call_stacy(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (call_stacy("(null)"));
	else
	{
		while (str [i])
			i++;
		write(1, str, i);
	}
	return (i);
}

int	telefonist(va_list contacts, char who_to_call)
{
	int	calls;

	calls = 0;
	if (who_to_call == '%')
		calls += call_charlie('%');
	else if (who_to_call == 'c')
		calls += call_charlie(va_arg(contacts, int));
	else if (who_to_call == 's')
		calls += call_stacy(va_arg(contacts, char *));
	else if (who_to_call == 'd' || who_to_call == 'i')
		calls += call_intelligence(va_arg(contacts, int));
	else if (who_to_call == 'p')
		calls += call_poncho(va_arg(contacts, unsigned long long));
	else if (who_to_call == 'u')
		calls += call_unintelligence(va_arg(contacts, unsigned int));
	else
		calls += call_professor(va_arg(contacts, unsigned int), who_to_call);
	return (calls);
}

int	ft_printf(const char *str, ...)
{
	int		chars_printed;
	va_list	contacts;
	size_t	i;

	chars_printed = 0;
	i = 0;
	va_start(contacts, str);
	while (str[i])
	{
		while (str[i] == '%')
		{
			chars_printed += telefonist(contacts, str[++i]);
			i++;
		}
		while (str[i] != '%' && str[i])
		{
			chars_printed += call_charlie(str[i]);
			i++;
		}
	}
	va_end(contacts);
	return (chars_printed);
}
