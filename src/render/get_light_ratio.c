#include "../../includes/minirt.h"

static double	get_light_ratio_sphere(t_data data, t_coordinate hit_point, t_ray *ray)
{
	double		light_ratio;
	t_ray		hit_to_light;
	t_vector	normal;
	void		*object;

	object = ray->object;
	hit_to_light.origin = hit_point;
	hit_to_light.direction = vector_unit(get_vector_two_point(hit_point, \
		data.light.coordinate));
	if (is_shadow(data, hit_to_light))
		return (0);
	normal = vector_unit(get_vector_two_point(((t_sphere *)object)->center, hit_point));
	light_ratio = vector_dot(normal, hit_to_light.direction);
	return (light_ratio);
}

static double	get_light_ratio_plane(t_data data, t_coordinate hit_point, t_ray *ray)
{
	double		light_ratio;
	t_ray		hit_to_light;
	t_vector	normal;
	void		*object;

	object = ray->object;
	hit_to_light.origin = hit_point;
	hit_to_light.direction = vector_unit(get_vector_two_point(hit_point, \
		data.light.coordinate));
	if (is_shadow(data, hit_to_light))
		return (0);
	normal = vector_unit(((t_plane *)object)->vector);
	light_ratio = vector_dot(normal, hit_to_light.direction);
	return (light_ratio);
}

double	get_light_ratio(t_data data, t_coordinate hit_point, t_ray *ray)
{
	if (ray->object_type == SPHERE)
		return (get_light_ratio_sphere(data, hit_point, ray));
	else
		return (get_light_ratio_plane(data, hit_point, ray));
}