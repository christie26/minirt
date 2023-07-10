#include "../../includes/minirt.h"

static t_vector	calculate_world_vertical(double x, double y, double z)
{
	t_vector	world_vertical;

	world_vertical = init_vector(0, 0, 0);
	if (fabs(x) > fabs(y) && fabs(x) > fabs(z))
	{
		world_vertical.y = y;
		world_vertical.z = z;
		world_vertical.x = -(pow(y, 2) + pow(z, 2)) / x;
	}
	else if (fabs(y) > fabs(x) && fabs(y) > fabs(z))
	{
		world_vertical.x = x;
		world_vertical.z = z;
		world_vertical.y = -(pow(x, 2) + pow(z, 2)) / y;
	}
	else if (fabs(z) > fabs(y) && fabs(z) > fabs(x))
	{
		world_vertical.x = x;
		world_vertical.y = y;
		world_vertical.z = -(pow(x, 2) + pow(y, 2)) / z;
	}
	return (world_vertical);
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
	world_vertical = calculate_world_vertical(x, y, z);
	return (world_vertical);
}

t_coordinate	get_start_corner(t_camera camera, t_vector horizontal, \
		t_vector vertical, double focal_length)
{
	t_coordinate	start_corner;
	t_vector		camera_unit;

	camera_unit = vector_unit(camera.vector);
	start_corner.x = camera.coordinate.x - horizontal.x / 2 - vertical.x / 2 \
		+ focal_length * camera_unit.x;
	start_corner.y = camera.coordinate.y - horizontal.y / 2 - vertical.y / 2 \
		+ focal_length * camera_unit.y;
	start_corner.z = camera.coordinate.z - horizontal.z / 2 - vertical.z / 2 \
		+ focal_length * camera_unit.z;
	return (start_corner);
}