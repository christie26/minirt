#include "../../includes/minirt.h"

int	blocked_plane(t_plane plane, t_ray ray)
{
	t_vector	ray_to_plane;
	double		denominator;
	double		t;

	ray_to_plane = vector_sub(init_vector(ray.origin.x, ray.origin.y, ray.origin.z), \
		init_vector(plane.coordinate.x, plane.coordinate.y, plane.coordinate.y));
	if (is_parallel(plane.vector, ray.direction, &denominator))
		return (0);
	t = vector_dot(ray_to_plane, plane.vector) / denominator;
	if (t < 0 || t > 1)
		return (0);
	return (1);
}

int	is_shadow(t_data data, t_ray hit_to_light)
{
	t_node *object;
	t_coordinate hit_point;

	object = data.object_list->headnode;
	hit_point = hit_to_light.origin;

	while (object)
	{
		if (object->type == SPHERE)
		{
			if (blocked_sphere(*(t_sphere *)object, hit_to_light))
			{
				printf("blocked by sphere\n");
				return (1);
			}
		}
		else
		{
			if (blocked_plane(*(t_plane *)object, hit_to_light))
			{
				printf("blocked by plane\n");
				return (1);
			}
		}
		object = object->next;
	}
	return (0);
}