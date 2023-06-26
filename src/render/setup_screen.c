#include "../../includes/minirt.h"

static double	degree_to_radian(double fov)
{
	double pi;

	pi = 3.14159265358979323846;
	fov = fov * pi / 180;
	return (fov);
}

t_coordinate  get_start_corner(t_coordinate origin, t_vector horizontal, \
                            t_vector vertical, double focal_length)
{
    t_coordinate    start_corner;

    start_corner.x = origin.x - horizontal.x / 2 - vertical.x / 2;
    start_corner.y = origin.y - horizontal.y / 2 - vertical.y / 2;
    start_corner.z = origin.z - horizontal.z / 2 - vertical.z / 2 - focal_length;
    return (start_corner);
}  

t_vector get_ray_direction(t_coordinate lower_left_corner, t_vector horizontal, \
                            t_vector vertical, t_coordinate origin, double u, double v)
{
    t_vector        ray_direction;
    t_coordinate    pixel;

    pixel.x = lower_left_corner.x + u * horizontal.x + v * vertical.x - origin.x;
    pixel.y = lower_left_corner.y + u * horizontal.y + v * vertical.y - origin.y;
    pixel.z = lower_left_corner.z + u * horizontal.z + v * vertical.z - origin.z;
    ray_direction = get_vector_two_point(origin, pixel);
    return (ray_direction);
}

void	setup_screen(t_data *data, int res_width, int res_height)
{
	t_vector	world_vertical;
	t_vector	horizontal;
	t_vector	vertical;

	data->screen.distance = 1;
	data->screen.window_width = res_width;
	data->screen.window_height = res_height;
	data->screen.view_width = 2 * tan(degree_to_radian(data->camera.fov));
	data->screen.view_height = data->screen.view_width * (res_height / (double)res_width);
	world_vertical = init_vector(0, 1, 0);
	horizontal = vector_unit(vector_cross(world_vertical, data->camera.vector));
	vertical = vector_unit(vector_cross(data->camera.vector, horizontal));
	data->screen.horizontal = horizontal;
	data->screen.vertical = vertical;
}
