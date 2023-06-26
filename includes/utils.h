#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

# include "model.h"
# include "vector.h"

// error.c
void	ft_putendl_fd(char *s, int fd);
void	*error_msg(char *error_message);
void	handle_syscall(void);

//free.c
void	free_two_dimensional_array(char **array);

// get double.c
double	get_double(const char *str);

// color_utils.c
int		rgb_to_hex(int r, int g, int b);
int		color_to_hex(t_color color);
t_color	gredient_color(t_color color_one, t_color color_two, double ratio);

// sphere
int		hit_sphere(t_sphere sphere, t_ray ray);

// math_utils.c
double	quadratic_equation_1(double a, double b, double c);
double	quadratic_equation_2(double a, double b, double c);


#endif
