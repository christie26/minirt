#include "../../includes/minirt.h"

int render_options = 0;

int	win_close(void)
{
	exit(EXIT_SUCCESS);
}

int	render(t_data *data)
{
	if (render_options)
		return (0);
	setup_screen(data);
	get_pixel_color(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	render_options = 1;
	return (0);
}
