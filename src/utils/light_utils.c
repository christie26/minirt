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

double	get_light_ratio(t_data data, t_coordinate hit_point, t_ray *ray, \
		t_light light)
{
	t_ray		hit_to_light;
	double			light_ratio;

	hit_to_light = get_hit_to_light(hit_point, light);
	if (is_shadow(data, hit_to_light))
		return (0);
	ray->hit_direction = hit_to_light.direction;
	light_ratio = vector_dot(ray->hit_normal, hit_to_light.direction);
	return (light_ratio);
}
