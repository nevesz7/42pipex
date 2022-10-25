/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 02:08:32 by rarobert          #+#    #+#             */
/*   Updated: 2022/10/25 03:29:04 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	***get_cmds(char *argv[])
{
	size_t	i;
	char	***cmds;

	cmds = (char ***)malloc(3 * sizeof(char **));
	i = 0;
	while (i < 2)
	{
		cmds[i] = ft_split(argv[i + 2], ' ');
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}

char	**get_path(char *envp[])
{
	size_t	i;
	char	*path_arr;

	i = -1;
	while (envp[++i])
		if (!(ft_strncmp("PATH", envp[i], 4)))
			path_arr = envp[i];
	return (ft_split(path_arr, ':'));
}
