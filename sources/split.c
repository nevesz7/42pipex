/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:13:48 by rarobert          #+#    #+#             */
/*   Updated: 2022/10/26 21:50:52 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			if (s[i] == '\'')
			{
				i++;
				while (s[i] != '\'')
					i++;
			}
			words++;
			while (s[i] && s[i] != c)
				i++;
		}	
	}
	return (words);
}

static char	**split_it(char **split, char const *s, char c, size_t words)
{
	size_t	i;
	size_t	j;
	int		len;

	i = 0;
	j = -1;
	while (++j < words)
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\'')
			len = gen_strlen(&s[++i], '\'');
		else
			len = gen_strlen(&s[i], c);
		split[j] = (char *)malloc(sizeof(char) * len);
		if (!split[j])
			return (NULL);
		if (s[i - 1] == '\'')
			ft_strlcpy(split[j], &s[i], len);
		else
			ft_strlcpy(split[j], &s[i], len);
		i += len;
	}
	return (split);
}

char	**pip_split(char const *s, char c)
{
	size_t	words;
	char	**split;

	words = ft_word_counter(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split_it(split, s, c, words);
	if (!split)
	{
		ft_free_array(split, (void *)split);
		return (NULL);
	}
	split[words] = NULL;
	return (split);
}
