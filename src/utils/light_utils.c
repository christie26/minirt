#include "../../includes/minirt.h"

void	fix_hit_to_light(t_ray *hit_to_light)
{
	hit_to_light->origin.x = hit_to_light->origin.x + EPSILON \
		* hit_to_light->direction.x;
	hit_to_light->origin.y = hit_to_light->origin.y + EPSILON \
		* hit_to_light->direction.y;
	hit_to_light->origin.z = hit_to_light->origin.z + EPSILON \
		* hit_to_light->direction.z;
}

t_ray	get_hit_to_light(t_coordinate hit_point, t_light light)
{
	t_ray	hit_to_light;

	hit_to_light.origin = hit_point;
	hit_to_light.direction = \
		vector_unit(get_vector_two_point(hit_point, light.coordinate));
	fix_hit_to_light(&hit_to_light);
	return (hit_to_light);
}
