#ifndef RENDER_H
# define RENDER_H

# include "model.h"

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
int rgb_to_hex(int r, int g, int b);
void first_ppm(t_data *data);
void	write_pixel_image(t_data *data, int x, int y, int color);

#endif