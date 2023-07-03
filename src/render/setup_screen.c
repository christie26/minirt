#include "../../includes/minirt.h"

static double	degree_to_radian(double fov)
{
	fov = fov * PI / 180;
	return (fov);
}

t_coordinate  get_start_corner(t_camera camera, t_vector horizontal, \
                            t_vector vertical, double focal_length)
{
    t_coordinate    start_corner;
	t_vector		camera_unit;

	camera_unit = vector_unit(camera.vector);
    start_corner.x = camera.coordinate.x - horizontal.x / 2 - vertical.x / 2 + focal_length * camera_unit.x;
    start_corner.y = camera.coordinate.y - horizontal.y / 2 - vertical.y / 2 + focal_length * camera_unit.y;
    start_corner.z = camera.coordinate.z - horizontal.z / 2 - vertical.z / 2 + focal_length * camera_unit.z;
	return (start_corner);
}

t_vector get_ray_direction(t_coordinate lower_left_corner, t_vector horizontal, \
                            t_vector vertical, t_coordinate origin, double u, double v)
{
    t_vector        ray_direction;
    t_coordinate    pixel;

    pixel.x = lower_left_corner.x + u * horizontal.x + v * vertical.x;
    pixel.y = lower_left_corner.y + u * horizontal.y + v * vertical.y;
    pixel.z = lower_left_corner.z + u * horizontal.z + v * vertical.z;
    ray_direction = get_vector_two_point(origin, pixel);
    return (ray_direction);
}

t_vector	get_world_vertical(t_vector camera_direction)
{
	t_vector	world_vertical;
	double		x;
	double		y;
	double		z;
	
	x = camera_direction.x;
	y = camera_direction.y;
	z = camera_direction.z;
	world_vertical = init_vector(0, 0, -1);
	if (vector_dot(camera_direction, world_vertical) == 0)
		return (world_vertical);
	world_vertical = init_vector(0, -1, 0);
	if (vector_dot(camera_direction, world_vertical) == 0)
		return (world_vertical);
	world_vertical = init_vector(-1, 0, 0);
	if (vector_dot(camera_direction, world_vertical) == 0)
		return (world_vertical);
	if (fabs(x) > fabs(y) && fabs(x) > fabs(z))
	{
		world_vertical.y = y;
		world_vertical.z = z;
		world_vertical.x = - (pow(y, 2) + pow(z, 2)) / x;
	}
	else if (fabs(y) > fabs(x) && fabs(y) > fabs(z))
	{
		world_vertical.x = x;
		world_vertical.z = z;
		world_vertical.y = - (pow(x, 2) + pow(z, 2)) / y;
	}
	else if (fabs(z) > fabs(y) && fabs(z) > fabs(x))
	{
		world_vertical.x = x;
		world_vertical.y = y;
		world_vertical.z = - (pow(x, 2) + pow(y, 2)) / z;
	}
	return (world_vertical);
}

void	setup_screen(t_data *data)
{
	t_vector	world_vertical;
	t_screen	screen;

	screen = data->screen;
	screen.distance = 1;
	screen.view_width = 2 * fabs(tan(degree_to_radian(data->camera.fov / 2)));
	screen.view_height = screen.view_width * (WINDOW_HEIGHT / (double)WINDOW_WIDTH);
	
	world_vertical = get_world_vertical(data->camera.vector);

	screen.horizontal = vector_unit(vector_cross(world_vertical, data->camera.vector));
	screen.horizontal = vector_mult_scalar(screen.horizontal, screen.view_width);

	screen.vertical = vector_unit(vector_cross(data->camera.vector, screen.horizontal));
	screen.vertical = vector_mult_scalar(screen.vertical, screen.view_height);
	// printf("vertical = (%.2f)");
	screen.start_point = get_start_corner(data->camera, screen.horizontal,screen.vertical, screen.distance);

	data->screen = screen;
}
