/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:32:54 by rarobert          #+#    #+#             */
/*   Updated: 2022/11/05 02:18:01 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipex {
	int		fd_out;
	int		fd_in;
	int		fd_r1;
	int		fd_r2;
	int		fd_w1;
	int		fd_w2;
	size_t	max;
	int		exit_code;
	pid_t	childs;
	char	*cmd;
	char	**path;
	char	***cmds;
}				t_pipex;

char	**get_path(char *envp[]);
char	***get_cmds(char *argv[], int argc);
void	pipe_it(t_pipex *pip);
void	get_cmd(char **path, size_t i, t_pipex *pip);
void	run_cmd(char **cmd, t_pipex pip);
void	print_3d(char ***arr);
void	cmd_error(char	*cmd);
void	ft_free3d(char ***arr);
void	free_pipe(t_pipex *pip);
void	manage_fds(size_t i, t_pipex *pip);
void	define_fds(size_t i, t_pipex *pip);
char	**pip_split(char const *s, char c);
char	**ft_splitfirst(char const *s, char c);
void	check_arguments(int argc, char *argv[], char *envp[], t_pipex *pip);

#endif