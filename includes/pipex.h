#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/types.h>

typedef struct s_ {
}				t_;

char	**get_path(char *envp[]);
char	***get_cmds(char *argv[]);
int		error_msg(int code);
void	print_3d(char ***arr);
void	ft_free3d(char ***arr);
void	check_parameter(int argc);

#endif