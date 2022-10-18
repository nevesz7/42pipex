#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	***cmds;

	if (argc == 5)
	{
		cmds = get_commands(argv);
	}
	check_args(argc, argv, envp);
	return (0);
}

char	***get_commands(char *argv[])
{
	size_t	i;
	char	**aux;
	char	***cmds;

	i = 0;
	cmds = (char ***)malloc(3 * sizeof(char **));
	cmds[0] = (char **)malloc(3 * sizeof(char *));
	cmds[1] = (char **)malloc(3 * sizeof(char *));
	cmds[2] = NULL;
	cmds[0][2] = NULL;
	cmds[1][2] = NULL;
	while (i <= 1)
	{
		aux = ft_split(argv[i + 2], ' ');
		cmds[i][0] = ft_strjoin("/bin/", aux[0]);
		if (aux[1])
			cmds[i][1] = ft_strdup(aux[1]);
		else
			cmds[i][1] = NULL;
		ft_free_array(aux, (void *)aux);
		i++;
	}
	return (cmds);
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
