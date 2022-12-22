/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 02:08:22 by rarobert          #+#    #+#             */
/*   Updated: 2022/12/20 23:20:20 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_arguments(int argc, char *argv[], char *envp[], t_pipex *pip)
{
	if (argc != 5)
	{
		if (argc < 5)
			ft_printf("Not enough parameters\n");
		else
			ft_printf("Too many parameters\n");
		ft_printf("Use: ./pipex infile cmd1 cmd2 outfile\n");
		exit(0);
	}
	pip->fd_in = open(argv[1], O_RDONLY);
	if (pip->fd_in < 0)
	{
		close(pip->fd_in);
		write(1, "bash: ", 6);
		perror(argv[1]);
	}
	pip->fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pip->fd_out < 0)
	{
		write(1, "bash: ", 6);
		perror(argv[argc - 1]);
		exit(EXIT_FAILURE);
	}
	pip->cmds = get_cmds(argv, argc);
	pip->path = get_path(envp);
	pip->exit_code = 0;
}

void	cmd_error(char	*cmd)
{
	write(2, "bash: ", 6);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
}
