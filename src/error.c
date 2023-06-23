
#include "../include/parse.h"

void	handle_syscall(void)
{
	perror("Error\n");
	exit(EXIT_FAILURE);
}

void	error_msg(char *error_message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(error_message, 2);
	exit(EXIT_FAILURE);
}