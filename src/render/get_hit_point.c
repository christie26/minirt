#include "../../includes/minirt.h"

t_coordinate	get_hit_point(t_ray *ray, t_node *node)
{
	t_coordinate hit_point;
	void *object;

	object = node->object;
	if (node->type == SPHERE)
		hit_point = get_closer_sphere_point(*(t_sphere *)object, ray);
	else
		hit_point = get_closer_plane_point(*(t_plane *)object, ray);
	return (hit_point);
}