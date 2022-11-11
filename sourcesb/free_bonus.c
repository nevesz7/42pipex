/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:21 by rarobert          #+#    #+#             */
/*   Updated: 2022/11/11 08:44:57 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	free(pip->cmd);
	close(pip->fd_in);
	close(pip->fd_out);
	if (pip->max % 2 == 0)
		close(pip->fd_r1);
	else
		close(pip->fd_r2);
	close(pip->fd_w1);
	close(pip->fd_w2);
	unlink("../temp_file1");
	unlink("../temp_file2");
}
