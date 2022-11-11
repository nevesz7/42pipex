/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:44:53 by rarobert          #+#    #+#             */
/*   Updated: 2022/11/11 13:25:05 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	define_fds(size_t i, t_pipex *pip)
{
	if (i == 0)
	{
		dup2(pip->fd_in, STDIN_FILENO);
		dup2(pip->fd_w1, STDOUT_FILENO);
		return ;
	}
	if (i % 2 == 0)
	{
		dup2(pip->fd_r2, STDIN_FILENO);
		if (i == pip->max - 1)
			dup2(pip->fd_out, STDOUT_FILENO);
		else
			dup2(pip->fd_w1, STDOUT_FILENO);
	}
	else
	{
		dup2(pip->fd_r1, STDIN_FILENO);
		if (i == pip->max - 1)
			dup2(pip->fd_out, STDOUT_FILENO);
		else
			dup2(pip->fd_w2, STDOUT_FILENO);
	}
}

void	manage_fds(size_t i, t_pipex *pip)
{
	if (i % 2 == 0)
	{
		if (i)
			pip->fd_r2 = open("../temp_file2", O_RDONLY);
		if (i != pip->max)
		{
			unlink("../temp_file1");
			pip->fd_w1 = open("../temp_file1",
					O_CREAT | O_WRONLY | O_TRUNC, 0644);
		}
	}
	else
	{
		pip->fd_r1 = open("../temp_file1", O_RDONLY);
		if (i != pip->max)
		{
			unlink("../temp_file2");
			pip->fd_w2 = open("../temp_file2",
					O_CREAT | O_WRONLY | O_TRUNC, 0644);
		}
	}
	define_fds(i, pip);
}
