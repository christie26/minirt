#include "../../includes/minirt.h"

static t_ray get_hit_to_light(t_data data, t_coordinate hit_point)
{
	t_ray		hit_to_light;

	hit_to_light.origin = hit_point;
	hit_to_light.direction = \
		vector_unit(get_vector_two_point(hit_point, data.light.coordinate));
	fix_hit_to_light(&hit_to_light);
	return (hit_to_light);
}

static double	get_light_ratio_sphere(t_data data, t_coordinate hit_point,
		t_ray *ray)
{
	double		light_ratio;
	t_ray		hit_to_light;
	t_vector	normal;
	t_sphere	*sphere;

	sphere = ray->object;
	hit_to_light = get_hit_to_light(data, hit_point);
	if (is_shadow(data, hit_to_light))
		return (0);
	normal = vector_unit(get_vector_two_point(sphere->center, \
				hit_point));
	ray->hit_normal = normal;
	ray->hit_direction = hit_to_light.direction;
	light_ratio = vector_dot(normal, hit_to_light.direction);
	return (light_ratio);
}

static double	get_light_ratio_plane(t_data data, t_coordinate hit_point,
		t_ray *ray)
{
	double		light_ratio;
	t_ray		hit_to_light;
	t_vector	normal;
	t_plane		*plane;

	plane = (t_plane *)ray->object;
	hit_to_light = get_hit_to_light(data, hit_point);
	if (is_shadow(data, hit_to_light))
		return (0);
	normal = vector_unit(plane->vector);
	ray->hit_normal = normal;
	ray->hit_direction = hit_to_light.direction;
	light_ratio = vector_dot(normal, hit_to_light.direction);
	return (light_ratio);
}

static double	get_light_ratio_cylinder(t_data data, t_coordinate hit_point,
		t_ray *ray)
{
	double		light_ratio;
	t_ray		hit_to_light;
	t_vector	normal;
	t_cylinder	*cylinder;
	t_vector	v;
	t_vector	p;

	cylinder = (t_cylinder *)ray->object;
	hit_to_light = get_hit_to_light(data, hit_point);
	if (is_shadow(data, hit_to_light))
		return (0);
	v = get_vector_two_point(cylinder->coordinate, hit_point);
	p = vector_add(coordinate_to_vector(cylinder->coordinate), \
			vector_mult_scalar(cylinder->vector, \
				vector_dot(v, cylinder->vector)));
	normal = vector_unit(vector_sub(init_vector(hit_point.x, hit_point.y, \
					hit_point.z), p));
	ray->hit_normal = normal;
	ray->hit_direction = hit_to_light.direction;
	light_ratio = vector_dot(normal, hit_to_light.direction);
	return (vector_dot(normal, hit_to_light.direction));
}

static double	get_light_ratio_paraboloid(t_data data, t_coordinate hit_point, t_ray *ray)
{
	double			light_ratio;
	t_ray			hit_to_light;
	// t_vector		normal;
    t_paraboloid	*paraboloid;

    paraboloid = (t_paraboloid *)(ray->object);
	hit_to_light.origin = hit_point;
	hit_to_light.direction = vector_unit(get_vector_two_point(hit_point, data.light.coordinate));
	fix_hit_to_light(&hit_to_light);
	if (is_shadow(data, hit_to_light))
		return (0);
	
	light_ratio = 1;
	// normal = vector_unit(get_vector_two_point((paraboloid->coordinate, hit_point));
	// light_ratio = vector_dot(normal, hit_to_light.direction);
	// return (light_ratio);
	// t_vector v = get_vector_two_point(paraboloid->coordinate, hit_point);
	// t_vector p = vector_add(paraboloid->vector, vector_mult_scalar(paraboloid->vector, vector_dot(v, paraboloid->vector)));
	// normal = vector_unit(vector_sub(init_vector(hit_point.x, hit_point.y, hit_point.z), p));

	// light_ratio = vector_dot(normal, hit_to_light.direction);
	return (light_ratio);
}

double	get_light_ratio(t_data data, t_coordinate hit_point, t_ray *ray)
{
	if (ray->object_type == SPHERE)
		return (get_light_ratio_sphere(data, hit_point, ray));
	else if (ray->object_type == PLANE)
		return (get_light_ratio_plane(data, hit_point, ray));
	else if (ray->object_type == CYLINDER)
		return (get_light_ratio_cylinder(data, hit_point, ray));
	else
		return (get_light_ratio_paraboloid(data, hit_point, ray));
}