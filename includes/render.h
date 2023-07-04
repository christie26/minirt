#ifndef RENDER_H
# define RENDER_H

# include "model.h"
# include "vector.h"
# include <stdbool.h>

# define DEG_TO_RAD(degrees) ((degrees)*PI / 180.0)
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

// render.c
int				key_press(int keycode, t_data *data);
int				win_close(void);
int				render(t_data *data);

// setup_screen.c
void			setup_screen(t_data *data);
t_coordinate	get_start_corner(t_camera camera, t_vector horizontal, \
					t_vector vertical, double focal_length);
t_vector		get_ray_direction(t_coordinate lower_left_corner, \
					t_vector horizontal, t_vector vertical, t_coordinate origin, \
					double u, double v);

//pixel color
double	get_short_distance(t_list *object_list, t_ray *ray);

// utils.c
void			write_pixel_image(t_data *data, int x, int y, int color);

// get_pixel_color.c
void			get_pixel_color(t_data *data);
t_color			apply_phong_model(t_data data, t_ray *ray);
t_color			get_checkerboard_sphere(t_sphere sphere, t_coordinate hit_point, t_screen screen);

// shadow_center.c
void			fix_hit_to_light(t_ray *hit_to_light);
int				is_shadow(t_data data, t_ray ray_to_light);

// get hit_point
t_coordinate	get_hit_point(t_ray *ray, t_node *node);
t_coordinate	get_closer_sphere_point(t_sphere sphere, t_ray *ray);
t_coordinate	get_closer_plane_point(t_plane plane, t_ray *ray);
t_coordinate	get_closer_cylinder_point(t_cylinder cylinder, t_ray *ray);
t_hit_sphere	hit_sphere(t_sphere sphere, t_ray ray);
int				is_parallel(t_vector vector1, t_vector vector2, double *dot_product);
t_hit_cylinder	hit_cylinder(t_cylinder cylinder, t_ray *ray);
t_coordinate	init_hit_point(void);
int is_hit_point_between_top_and_bottom(double hit_base, double hit_top, double height);

// light ratio
double			get_light_ratio(t_data data, t_coordinate hit_point, \
					t_ray *ray);
t_color	get_specular_color(t_ray *ray, t_light light, double light_ratio);

#endif