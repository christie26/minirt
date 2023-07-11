#include "../../includes/minirt.h"

static double	get_light_ratio_sphere(t_data data, t_coordinate hit_point,
		t_ray *ray, t_light light)
{
	double		light_ratio;
	t_ray		hit_to_light;
	t_sphere	*sphere;

	sphere = ray->object;
	hit_to_light = get_hit_to_light(hit_point, light);
	if (is_shadow(data, hit_to_light))
		return (0);
	ray->hit_direction = hit_to_light.direction;
	light_ratio = vector_dot(ray->hit_normal, hit_to_light.direction);
	return (light_ratio);
}

static double	get_light_ratio_plane(t_data data, t_coordinate hit_point,
		t_ray *ray, t_light light)
{
	double		light_ratio;
	t_ray		hit_to_light;
	t_plane		*plane;

	plane = (t_plane *)ray->object;
	hit_to_light = get_hit_to_light(hit_point, light);
	if (is_shadow(data, hit_to_light))
		return (0);
	ray->hit_direction = hit_to_light.direction;
	light_ratio = vector_dot(ray->hit_normal, hit_to_light.direction);
	return (light_ratio);
}

static double	get_light_ratio_cylinder(t_data data, t_coordinate hit_point,
		t_ray *ray, t_light light)
{
	double		light_ratio;
	t_ray		hit_to_light;
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)ray->object;
	hit_to_light = get_hit_to_light(hit_point, light);
	if (is_shadow(data, hit_to_light))
		return (0);
	ray->hit_direction = hit_to_light.direction;
	light_ratio = vector_dot(ray->hit_normal, hit_to_light.direction);
	return (light_ratio);
}

static double	get_light_ratio_paraboloid(t_data data, t_coordinate hit_point,
		t_ray *ray, t_light light)
{
	double			light_ratio;
	t_ray			hit_to_light;
	t_paraboloid	*paraboloid;

	paraboloid = (t_paraboloid *)(ray->object);
	hit_to_light = get_hit_to_light(hit_point, light);
	if (is_shadow(data, hit_to_light))
		return (0);
	ray->hit_direction = hit_to_light.direction;
	light_ratio = vector_dot(ray->hit_normal, hit_to_light.direction);
	return (light_ratio);
}

double	get_light_ratio(t_data data, t_coordinate hit_point, t_ray *ray, \
		t_light light)
{
	if (ray->object_type == SPHERE)
		return (get_light_ratio_sphere(data, hit_point, ray, light));
	else if (ray->object_type == PLANE)
		return (get_light_ratio_plane(data, hit_point, ray, light));
	else if (ray->object_type == CYLINDER)
		return (get_light_ratio_cylinder(data, hit_point, ray, light));
	else
		return (get_light_ratio_paraboloid(data, hit_point, ray, light));
}
