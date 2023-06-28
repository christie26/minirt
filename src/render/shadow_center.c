#include "../../includes/minirt.h"

void	fix_hit_to_light(t_ray *hit_to_light)
{
	hit_to_light->origin.x = hit_to_light->origin.x + 0.01 *  hit_to_light->direction.x;
	hit_to_light->origin.y = hit_to_light->origin.y + 0.01 *  hit_to_light->direction.y;
	hit_to_light->origin.z = hit_to_light->origin.z + 0.01 *  hit_to_light->direction.z;
}

int	is_shadow(t_data data, t_ray ray_to_light)
{
	if (shadow_sphere(data.sphere, ray_to_light))
		return (1);
	return (0);
}