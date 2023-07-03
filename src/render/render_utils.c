#include "../../includes/minirt.h"

t_coordinate	get_closer_point(t_coordinate hit_point_1, t_coordinate hit_point_2, t_ray ray)
{
	if (get_distance(ray.origin, hit_point_1) < get_distance(ray.origin, hit_point_2))
		return(hit_point_1);
	return (hit_point_2);
}

