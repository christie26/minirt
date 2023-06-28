#include "../../includes/minirt.h"

t_coordinate	calculate_hit_point(t_ray ray, double t)
{
	t_coordinate hit_point;

	hit_point.x = ray.origin.x + ray.direction.x * t;
	hit_point.y = ray.origin.y + ray.direction.y * t;
	hit_point.z = ray.origin.z + ray.direction.z * t;
	return (hit_point);
}

double get_distance(t_coordinate start, t_coordinate end)
{
	t_vector diff;

	diff = get_vector_of_two_point(start, end);
	return (vector_length(diff));
}