#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	**path;
	char	***cmds;
	size_t	i;

	if (argc != 5)
		return (error_msg(1));
	cmds = get_cmds(argv);
	path = get_path(envp);
	i = -1;
	while (path[++i])
		ft_printf("[%s]\n", path[i]);
	print_3d(cmds);
	return (0);
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

int	error_msg(int code)
{
	if (code == 1)
		ft_printf("Input needs to be 5 arguments.");
	return (0);
}
