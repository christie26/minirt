#include "../../includes/minirt.h"

static double	degree_to_radian(double fov)
{
	double pi;

	pi = 3.14159265358979323846;
	fov = fov * pi / 180;
	return (fov);
}

void	setup_screen(t_data *data, int res_width, int res_height)
{
	t_vector	world_vertical;
	t_vector	horizontal;
	t_vector	vertical;

	data->screen.distance = 1;
	data->screen.resolution_width = res_width;
	data->screen.resolution_height = res_height;
	data->screen.width = 2 * tan(degree_to_radian(data->camera.fov));
	data->screen.height = data->screen.width * (res_height / (double)res_width);
	world_vertical = init_vector(0, 1, 0);
	horizontal = vector_unit(vector_cross(world_vertical, data->camera.vector));
	vertical = vector_unit(vector_cross(data->camera.vector, horizontal));
	data->screen.horizontal = horizontal;
	data->screen.vertical = vertical;
}
