#include "../../includes/minirt.h"

void	fix_hit_to_light(t_ray *hit_to_light)
{
	hit_to_light->origin.x = hit_to_light->origin.x + 0.1 *  hit_to_light->direction.x;
	hit_to_light->origin.y = hit_to_light->origin.y + 0.1 *  hit_to_light->direction.y;
	hit_to_light->origin.z = hit_to_light->origin.z + 0.1 *  hit_to_light->direction.z;
}

static int	blocked_plane(t_plane plane, t_ray hit_to_light)
{
	t_vector	ray_to_plane;
	double		denominator;
	double		t;

	ray_to_plane = get_vector_two_point(hit_to_light.origin, plane.coordinate);
	if (is_parallel(plane.vector, hit_to_light.direction, &denominator))
		return (0);
	t = vector_dot(ray_to_plane, plane.vector) / denominator;
	return (t >= 0);
}

int blocked_sphere(t_sphere sphere, t_ray hit_to_light)
{
	t_hit_sphere	info;

	info = hit_sphere(sphere, hit_to_light);
	return (info.t_1 > 0 || info.t_2 > 0);
}

static int blocked_cylinder(t_cylinder cylinder, t_ray hit_to_light)
{
	t_hit_cylinder	info;

	info = hit_cylinder(cylinder, &hit_to_light);
	if (info.t_1 < 0 && info.t_2 < 0)
		return (0);
	if ((info.base >= 0 && info.base <= cylinder.height) || (info.top >= 0 && info.top <= cylinder.height))
		return (0);
	return (1);
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
		else if (node->type == PLANE)
		{
			if (blocked_plane(*(t_plane *)object, hit_to_light))
				return (1);
		}
		else if (node->type == CYLINDER)
		{
			if (blocked_cylinder(*(t_cylinder *)object, hit_to_light))
				return (1);
		}
		node = node->next;
	}
	return (0);
}