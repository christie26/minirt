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
int		key_press(int keycode, t_data *data);
int		win_close(void);
int		render(t_data *data);
void	setup_screen(t_data *data, int res_width, int res_height);


// utils.c
void	write_pixel_image(t_data *data, int x, int y, int color);

// rednering trial
void	first_ppm(t_data *data);
void	simple_render(t_data *data);

#endif