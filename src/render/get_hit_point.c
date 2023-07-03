#include "../../includes/minirt.h"

t_coordinate init_hit_point(void)
{
	t_coordinate hit_point;

	hit_point.x = INFINITY;
	hit_point.y = INFINITY;
	hit_point.z = INFINITY;
	return (hit_point);
}

t_coordinate	get_hit_point(t_ray *ray, t_node *node)
{
	t_coordinate hit_point;
	void *object;

	object = node->object;
	if (node->type == SPHERE)
		hit_point = get_closer_sphere_point(*(t_sphere *)object, ray);
	else if (node->type == PLANE)
		hit_point = get_closer_plane_point(*(t_plane *)object, ray);
	else
		hit_point = get_closer_cylinder_point(*(t_cylinder *)object, ray);
	return (hit_point);
}