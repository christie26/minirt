
#include "../include/parse.h"

void	*handle_syscall(char *error_message)
{
	perror(error_message);
	return (0);
}

void	*error_msg(char *error_message)
{
	ft_putendl_fd(error_message, 2);
	return (0);
}