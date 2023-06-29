#include "../../includes/minirt.h"

void	fix_hit_to_light(t_ray *hit_to_light)
{
	hit_to_light->origin.x = hit_to_light->origin.x + 0.01 *  hit_to_light->direction.x;
	hit_to_light->origin.y = hit_to_light->origin.y + 0.01 *  hit_to_light->direction.y;
	hit_to_light->origin.z = hit_to_light->origin.z + 0.01 *  hit_to_light->direction.z;
}

int	is_shadow(t_data data, t_ray hit_to_light)
{
	t_node			*object;
	t_coordinate	hit_point;

	object = data.object_list->headnode;
	hit_point = hit_to_light.origin;

// while to check each object
	while (object)
	{
		if (object->type == SPHERE)
			if (shadow_sphere(*(t_sphere *)object, hit_to_light))
			return (1);
		// 	hit_point = get_closer_sphere_point(*(t_sphere *)object->object, ray);
		// // else if (object->type == PLANE)
		// 	// distance = get_closer_plane_point(*(t_plane *)object->object, ray);
		// if (short_distance > get_distance(hit_point, ray->origin))
		// {
		// 	ray->object = object;
		// 	ray->object_type = object->type;
		// 	ray->hit_point = hit_point;
		// 	short_distance = get_distance(hit_point, ray->origin);
		// }
		object = object->next;
	}
	return (0);
}