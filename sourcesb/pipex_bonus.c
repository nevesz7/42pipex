/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 02:08:29 by rarobert          #+#    #+#             */
/*   Updated: 2022/11/05 02:30:59 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pip;

	check_arguments(argc, argv, envp, &pip);
	pip.cmd = ft_strdup("");
	pipe_it(&pip);
	free_pipe(&pip);
	exit(pip.exit_code);
	return (0);
}

void	pipe_it(t_pipex *pip)
{
	size_t	i;

	i = -1;
	while (++i < pip->max)
	{
		get_cmd(pip->path, i, pip);
		manage_fds(i, pip);
		run_cmd(pip->cmds[i], *pip);
	}
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
			return ;
		free(pip->cmds[i][0]);
	}
	pip->cmds[i][0] = ft_strdup("");
	cmd_error(pip->cmd);
	pip->exit_code = 127;
	return ;
}

void	run_cmd(char **cmd, t_pipex pip)
{
	pip.childs = fork();
	if (pip.childs == 0)
		execve(cmd[0], cmd, NULL);
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