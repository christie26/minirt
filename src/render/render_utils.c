#include "../../includes/minirt.h"

t_coordinate	get_closer_point(t_coordinate hit_point_1, t_coordinate hit_point_2, t_ray ray)
{
	if (get_distance(ray.origin, hit_point_1) < get_distance(ray.origin, hit_point_2))
		return(hit_point_1);
	return (hit_point_2);
}

t_coordinate get_closer_hit_point(double t_1, double t_2, t_ray ray)
{
	t_coordinate closer_hit_point;

	closer_hit_point = get_closer_point(calculate_hit_point(ray, t_1), calculate_hit_point(ray, t_2), ray);
	return (closer_hit_point);
}
