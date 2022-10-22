#include "pipex.h"

void	check_parameter(int argc)
{
	if (argc < 5)
	{
		ft_printf("Not enough parameters\n");
		ft_printf("Use: ./pipex infile cmd1 cmd2 outfile\n");
	}
}
