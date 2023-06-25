#ifndef UTILS_H
# define UTILS_H

// error.c
void	ft_putendl_fd(char *s, int fd);
void	*error_msg(char *error_message);
void	handle_syscall(void);

//free.c
void	free_two_dimensional_array(char **array);

// get double.c
double	get_double(const char *str);

#endif
