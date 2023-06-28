#include "../../includes/minirt.h"

int render_options = 0;

int	win_close(void)
{
	exit(EXIT_SUCCESS);
}

static t_render	get_rendering_info(t_data data)
{
	t_render	render;

	render.window_width = data.screen.window_width;
	render.window_height = data.screen.window_height;
	render.focal_length = data.screen.distance;
	render.origin = data.camera.coordinate;
	render.horizontal = init_vector(data.screen.view_width, 0, 0);
	render.vertical = init_vector(0, data.screen.view_height, 0);
	render.lower_left_corner = get_start_corner(render.origin, render.horizontal, \
			render.vertical, render.focal_length);
	return (render);
}

int	render(t_data *data)
{
	t_render	render;

	if (render_options)
		return (0);
	setup_screen(data, 1920, 1080);
	render = get_rendering_info(*data);
	get_pixel_color(data, render);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	render_options = 1;
	return (0);
}
