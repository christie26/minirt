#ifndef RENDER_H
# define RENDER_H

# include <stdbool.h>

# include "model.h"
# include "vector.h"

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
int	key_press(int keycode, t_data *data);
int	win_close(void);
int	render(t_data *data);

// utils.c
void	write_pixel_image(t_data *data, int x, int y, int color);

// rednering trial
void	first_ppm(t_data *data);
bool	hit_sphere(t_coordinate center, double radius, t_ray ray);
void	simple_render(t_data *data);

#endif