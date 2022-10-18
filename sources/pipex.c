#include "libft.h"
#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	check_args(argc, argv, envp);
	return (0);
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