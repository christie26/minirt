#ifndef UTILS_H
# define UTILS_H

# include "model.h"
# include "vector.h"
# include <stdbool.h>
# define PI 3.14159265358979323846

// linked list.c
t_list			*create_linkedlist(void);
t_node			*create_new_node(void *object, int type);
t_node			*get_node(t_list *linked_list, size_t index);
int				add_node(t_list **linked_list, void *object, int type);
void			destroy_list(t_list **linked_list);

// error.c
void			ft_putendl_fd(char *s, int fd);
void			*error_msg(char *error_message);
void			handle_syscall(void);

//free.c
void			free_two_dimensional_array(char **array);

// get double.c
double			get_double(const char *str);

// color_utils.c
int				rgb_to_hex(int r, int g, int b);
int				color_to_hex(t_color color);

// change_color.c
t_color			mix_color(t_color color_one, t_color color_two, double ratio);
t_color			apply_brightness(t_color color, double brightness);
t_color			add_color(t_color color_one, t_color color_two);
t_color			multiply_color(t_color color_one, t_color color_two);

// sphere
int				blocked_sphere(t_sphere sphere, t_ray ray);
t_coordinate	get_closer_point(t_coordinate hit_point_1,
								t_coordinate hit_point_2,
								t_ray ray);
t_coordinate	get_closer_hit_point(double a, double b, double c, t_ray ray);

// math_utils.c
double			quadratic_equation_1(double a, double b, double c);
double			quadratic_equation_2(double a, double b, double c);
int				ft_min(int a, int b);
int				is_same_coordinate(t_coordinate one, t_coordinate two);
double			radian_to_degree(double radian);

#endif
