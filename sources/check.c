#include "pipex.h"

void	check_parameter(int argc)
{
	if (argc < 5)
	{
		ft_printf("Not enough parameters\n");
		ft_printf("Use: ./pipex infile cmd1 cmd2 outfile\n");
	}
}

void	check_args(int argc, char *argv[], char *envp[])
{
	size_t	i;

	i = -1;
	ft_printf("argc = %d\n", argc);
	while (argv[++i])
		ft_printf("argv[%d] = %s\n", i, argv[i]);
	while (envp[i])
		i++;
	ft_printf("envp size = %d\n", i);
}
