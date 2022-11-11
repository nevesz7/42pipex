/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 02:08:29 by rarobert          #+#    #+#             */
/*   Updated: 2022/11/11 18:50:19 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pip;

	check_arguments(argc, argv, envp, &pip);
	pipe(pip.pipe);
	pip.cmd = ft_strdup("");
	pipe_it(&pip, argc);
	free_pipe(&pip);
	exit(pip.exit_code);
	return (0);
}

void	pipe_it(t_pipex *pip, int argc)
{
	int	i;

	i = -1;
	if (pip->fd_in < 0)
		i++;
	while (++i < argc - 4)
	{
		get_cmd(pip->path, i, pip);
		if (pip->cmds[i][0][0] != 0)
			run_cmd(pip->cmds[i], i, *pip);
		else
			write(pip->pipe[1], "", 0);
	}
	get_cmd(pip->path, i, pip);
	dup2(pip->pipe[0], STDIN_FILENO);
	dup2(pip->fd_out, STDOUT_FILENO);
	close(pip->pipe[1]);
	if (pip->cmds[i][0][0])
		run_cmd(pip->cmds[i], i, *pip);
	wait(&pip->child);
}

void	get_cmd(char **path, size_t i, t_pipex *pip)
{
	size_t	j;

	free(pip->cmd);
	pip->cmd = ft_strdup(pip->cmds[i][0]);
	free(pip->cmds[i][0]);
	j = 0;
	while (path[++j])
	{
		pip->cmds[i][0] = ft_strjoin(path[j], "/");
		pip->cmds[i][0] = ft_strjoin_free(pip->cmds[i][0], pip->cmd);
		if (access(pip->cmds[i][0], 0) == 0)
		{
			pip->exit_code = 0;
			return ;
		}
		free(pip->cmds[i][0]);
	}
	pip->cmds[i][0] = ft_strdup("");
	cmd_error(pip->cmd);
	pip->exit_code = 127;
	return ;
}

void	run_cmd(char **cmd, int i, t_pipex pip)
{
	pip.child = fork();
	if (pip.child == 0)
	{
		if (i == 0)
			dup2(pip.fd_in, STDIN_FILENO);
		dup2(pip.pipe[1], STDOUT_FILENO);
		close(pip.pipe[0]);
		close(pip.pipe[1]);
		execve(cmd[0], cmd, NULL);
	}
}

void	print_3d(char ***arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			ft_printf("arr[%d][%d] = %s\n", i, j, arr[i][j]);
			j++;
		}
		i++;
	}
}
