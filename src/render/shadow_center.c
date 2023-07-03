#include "../../includes/minirt.h"

void	fix_hit_to_light(t_ray *hit_to_light)
{
	hit_to_light->origin.x = hit_to_light->origin.x + 0.1 *  hit_to_light->direction.x;
	hit_to_light->origin.y = hit_to_light->origin.y + 0.1 *  hit_to_light->direction.y;
	hit_to_light->origin.z = hit_to_light->origin.z + 0.1 *  hit_to_light->direction.z;
}

int	blocked_plane(t_plane plane, t_ray ray)
{
	t_vector	ray_to_plane;
	double		denominator;
	double		t;

	ray_to_plane = vector_sub(init_vector(ray.origin.x, ray.origin.y, ray.origin.z), \
		init_vector(plane.coordinate.x, plane.coordinate.y, plane.coordinate.z));
	if (is_parallel(plane.vector, ray.direction, &denominator))
		return (0);
	t = vector_dot(ray_to_plane, plane.vector) / denominator;
	if (t < 0 || t > 1)
		return (0);
	return (1);
}

int blocked_sphere(t_sphere sphere, t_ray ray)
{
	t_hit_sphere	info;

	info = hit_sphere(sphere, ray);
	return (info.t_1 > 0 || info.t_2 > 0);
}

int	is_shadow(t_data data, t_ray hit_to_light)
{
	t_node			*node;
	void			*object;
	t_coordinate	hit_point;

	node = data.object_list->headnode;
	hit_point = hit_to_light.origin;
	while (node)
	{
		object = node->object;
		if (node->type == SPHERE)
		{
			if (blocked_sphere(*(t_sphere *)object, hit_to_light))
				return (1);
		}
		else
		{
			// if (blocked_plane(*(t_plane *)object, hit_to_light))
			// {
			// 	printf("blocked by plane\n");
			// 	return (1);
			// }
		}
		node = node->next;
	}
	return (0);
}