#include "../../includes/minirt.h"

t_coordinate	calculate_hit_point(t_ray ray, double t)
{
	t_coordinate	hit_point;

	hit_point.x = ray.origin.x + ray.direction.x * t;
	hit_point.y = ray.origin.y + ray.direction.y * t;
	hit_point.z = ray.origin.z + ray.direction.z * t;
	return (hit_point);
}

double	get_distance(t_coordinate start, t_coordinate end)
{
	t_vector	diff;

	diff = get_vector_two_point(start, end);
	return (vector_length(diff));
}

t_vector	rotate_vector(t_vector vec, t_vector rotation_angle)
{
	const double	cos_x = cos(rotation_angle.x);
	const double	sin_x = sin(rotation_angle.x);
	const double	cos_y = cos(rotation_angle.y);
	const double	sin_y = sin(rotation_angle.y);
	t_vector		result;

	result.y = cos_x * vec.y - sin_x * vec.z;
	result.z = sin_x * vec.y + cos_x * vec.z;
	vec.y = result.y;
	vec.z = result.z;
	result.x = cos_y * vec.x + sin_y * vec.z;
	result.z = -sin_y * vec.x + cos_y * vec.z;
	return (result);
}
