/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 02:08:27 by rarobert          #+#    #+#             */
/*   Updated: 2022/10/25 02:08:28 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free3d(char ***arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		ft_free_array(arr[i], (void *)arr[i]);
		i++;
	}
	free(arr);
}

void	free_pipe(t_pipex	*pip)
{
	ft_free3d(pip->cmds);
	ft_free_array(pip->path, (void *)pip->path);
	if (pip->cmd[0])
		free(pip->cmd);
	close(pip->pipe[0]);
	close(pip->pipe[1]);
}
