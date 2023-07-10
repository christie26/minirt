#include "../../includes/minirt.h"

void	fix_hit_to_light(t_ray *hit_to_light)
{
	hit_to_light->origin.x = hit_to_light->origin.x + 0.1 \
		* hit_to_light->direction.x;
	hit_to_light->origin.y = hit_to_light->origin.y + 0.1 \
		* hit_to_light->direction.y;
	hit_to_light->origin.z = hit_to_light->origin.z + 0.1 \
		* hit_to_light->direction.z;
}
