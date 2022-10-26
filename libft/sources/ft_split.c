/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:44:25 by rarobert          #+#    #+#             */
/*   Updated: 2022/10/11 04:16:12 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	gen_strlen(char const *str, char delim)
{
	size_t	i;

	i = 0;
	while (str[i] != delim && str[i])
		i++;
	return (i + 1);
}

static size_t	ft_word_counter(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}	
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	words;
	size_t	j;
	char	**split;

	words = ft_word_counter(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	i = 0;
	j = -1;
	while (++j < words)
	{
		while (s[i] == c)
			i++;
		split[j] = (char *)malloc(sizeof(char) * (gen_strlen(&s[i], c)));
		if (!split[j])
		{
			ft_free_array(split, (void *)split);
			return (0);
		}
		ft_strlcpy(split[j], &s[i], gen_strlen(&s[i], c));
		i += gen_strlen(&s[i], c);
	}
	split[j] = (NULL);
	return (split);
}
