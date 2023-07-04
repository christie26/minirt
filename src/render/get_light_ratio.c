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
	fix_hit_to_light(&hit_to_light);
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
	fix_hit_to_light(&hit_to_light);
	if (is_shadow(data, hit_to_light))
		return (0);
	normal = vector_unit(((t_plane *)object)->vector);
	light_ratio = vector_dot(normal, hit_to_light.direction);
	return (light_ratio);
}

static double	get_light_ratio_cylinder(t_data data, t_coordinate hit_point, t_ray *ray)
{
	double		light_ratio;
	t_ray		hit_to_light;
	t_vector	normal;
	void		*object;
    t_cylinder  *cylinder;

	object = ray->object;
    cylinder = (t_cylinder *)object;
	hit_to_light.origin = hit_point;
	hit_to_light.direction = vector_unit(get_vector_two_point(hit_point, data.light.coordinate));
	fix_hit_to_light(&hit_to_light);
	if (is_shadow(data, hit_to_light))
		return (0);
	
	// to get the normal vector of a point on the cylinder, 
	// first find the vector from the cylinder center to the hit_point (v),
	// then project v onto the cylinder's axis to find the closest point on the axis to the hit_point (p),
	// and finally, the normal is the unit vector from p to the hit_point.
	t_vector v = get_vector_two_point(cylinder->coordinate, hit_point);
	t_vector p = vector_add(cylinder->vector, vector_mult_scalar(cylinder->vector, vector_dot(v, cylinder->vector)));
	normal = vector_unit(vector_sub(init_vector(hit_point.x, hit_point.y, hit_point.z), p));

	light_ratio = vector_dot(normal, hit_to_light.direction);
	return (light_ratio);
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