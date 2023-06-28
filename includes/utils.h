#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

# include "model.h"
# include "vector.h"
# define PI 3.14159265358979323846

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

// change_color.c
t_color	mix_color(t_color color_one, t_color color_two, double ratio);
t_color	apply_brightness(t_color color, double brightness);
t_color	add_color(t_color color_one, t_color color_two);
t_color	multiply_color(t_color color_one, t_color color_two);


// sphere
int				shadow_sphere(t_sphere sphere, t_ray ray);
t_coordinate	get_closer_point(t_coordinate hit_point_1, t_coordinate hit_point_2, t_ray ray);
t_coordinate get_closer_hit_point(double a, double b, double c, t_ray ray);

// math_utils.c
double	quadratic_equation_1(double a, double b, double c);
double	quadratic_equation_2(double a, double b, double c);
int	ft_min(int a, int b);


#endif
