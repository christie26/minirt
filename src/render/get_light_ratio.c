#include "../../includes/minirt.h"

static t_ray get_hit_to_light(t_coordinate hit_point, t_light light)
{
	t_ray		hit_to_light;

	hit_to_light.origin = hit_point;
	hit_to_light.direction = \
		vector_unit(get_vector_two_point(hit_point, light.coordinate));
	fix_hit_to_light(&hit_to_light);
	return (hit_to_light);
}

static double	get_light_ratio_sphere(t_data data, t_coordinate hit_point,
		t_ray *ray, t_light light)
{
	double		light_ratio;
	t_ray		hit_to_light;
	t_vector	normal;
	t_sphere	*sphere;

	sphere = ray->object;
	hit_to_light = get_hit_to_light(hit_point, light);
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
		t_ray *ray, t_light light)
{
	double		light_ratio;
	t_ray		hit_to_light;
	t_vector	normal;
	t_plane		*plane;

	plane = (t_plane *)ray->object;
	hit_to_light = get_hit_to_light(hit_point, light);
	if (is_shadow(data, hit_to_light))
		return (0);
	normal = vector_unit(plane->vector);
	ray->hit_normal = normal;
	ray->hit_direction = hit_to_light.direction;
	light_ratio = vector_dot(normal, hit_to_light.direction);
	return (light_ratio);
}

static double	get_light_ratio_cylinder(t_data data, t_coordinate hit_point,
		t_ray *ray, t_light light)
{
	double		light_ratio;
	t_ray		hit_to_light;
	t_vector	normal;
	// t_vector	lid_normal;
	t_cylinder	*cylinder;
	t_vector	v;
	t_vector	p;
	t_coordinate	lid_point;

	cylinder = (t_cylinder *)ray->object;
	hit_to_light = get_hit_to_light(hit_point, light);
	if (is_shadow(data, hit_to_light))
		return (0);
	lid_point = hit_cylinder_lid(*cylinder, ray, cylinder->top, cylinder->base);
	if (lid_point.x == hit_to_light.hit_point.x && \
			lid_point.y == hit_to_light.hit_point.y && \
			lid_point.z == hit_to_light.hit_point.z)
		normal = cylinder->vector;
	else
	{
		v = get_vector_two_point(cylinder->base, hit_point);
		p = vector_add(coordinate_to_vector(cylinder->base), \
				vector_mult_scalar(cylinder->vector, \
					vector_dot(v, cylinder->vector)));
		normal = vector_unit(vector_sub(init_vector(hit_point.x, hit_point.y, \
						hit_point.z), p));
	}
	ray->hit_normal = normal;
	ray->hit_direction = hit_to_light.direction;
	light_ratio = vector_dot(normal, hit_to_light.direction);
	return (light_ratio);
}

static double	get_light_ratio_paraboloid(t_data data, t_coordinate hit_point, t_ray *ray, t_light light)
{
	double			light_ratio;
	t_ray			hit_to_light;
	// t_vector		normal;
    t_paraboloid	*paraboloid;

    paraboloid = (t_paraboloid *)(ray->object);
	hit_to_light = get_hit_to_light(hit_point, light);
	if (is_shadow(data, hit_to_light))
		return (0);
	ray->hit_direction = hit_to_light.direction;
	light_ratio = vector_dot(ray->hit_normal, hit_to_light.direction);
	// printf("light_ratio = %.2f\n", light_ratio);
	// light_ratio = 1;
	return (light_ratio);
}

double	get_light_ratio(t_data data, t_coordinate hit_point, t_ray *ray, t_light light)
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