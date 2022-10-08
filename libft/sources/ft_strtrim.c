/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:16:21 by rarobert          #+#    #+#             */
/*   Updated: 2022/05/12 21:04:31 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	int		i;
	char	*trim;

	start = -1;
	len = ft_strlen(s1);
	while (s1[++start])
		if (ft_strchr(set, s1[start]) == NULL)
			break ;
	while (--len > 1)
		if (ft_strchr(set, s1[len]) == NULL)
			break ;
	if (start > len)
		return (ft_strdup(""));
	trim = (char *)malloc(sizeof(char) * (len - start + 2));
	if (!trim)
		return (NULL);
	i = -1;
	while (++i < (len - start + 1))
		trim[i] = s1[start + i];
	trim[i] = '\0';
	return (trim);
}
