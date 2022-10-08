/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:21:34 by rarobert          #+#    #+#             */
/*   Updated: 2022/04/15 13:09:32 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapi;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	mapi = (char *)malloc(sizeof(char) * (len + 1));
	if (!mapi)
		return (NULL);
	i = 0;
	while (i++ < len)
		mapi[i - 1] = (*f)(i - 1, s[i - 1]);
	mapi[i - 1] = '\0';
	return (mapi);
}
