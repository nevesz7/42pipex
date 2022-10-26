/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 02:08:36 by rarobert          #+#    #+#             */
/*   Updated: 2022/10/26 08:14:30 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipex {
	int		fd_out;
	int		fd_in;
	int		exit_code;
	int		pipe[2];
	pid_t	child;
	char	*cmd;
	char	**path;
	char	***cmds;
}				t_pipex;

char	**get_path(char *envp[]);
char	***get_cmds(char *argv[]);
void	pipe_it(t_pipex *pip, int argc);
void	get_cmd(char **path, size_t i, t_pipex *pip);
void	run_cmd(char **cmd, int i, t_pipex pip);
void	print_3d(char ***arr);
void	cmd_error(char	*cmd);
void	ft_free3d(char ***arr);
void	free_pipe(t_pipex *pip);
char	**pip_split(char const *s, char c);
char	**ft_splitfirst(char const *s, char c);
void	check_arguments(int argc, char *argv[], char *envp[], t_pipex *pip);

#endif