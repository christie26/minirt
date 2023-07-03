#include "../../includes/minirt.h"

double get_hit_base(t_ray *ray, t_cylinder cylinder, double t)
{
	t_coordinate	intersection_point;
	t_vector		base_to_intersection;

	intersection_point = calculate_hit_point(*ray, t);
	base_to_intersection = get_vector_two_point(cylinder.coordinate, intersection_point);
	return vector_dot(base_to_intersection, cylinder.vector);
}

double get_hit_top(t_ray *ray, t_cylinder cylinder, double t)
{
	t_coordinate	intersection_point;
	t_vector		base_to_intersection;

	intersection_point = calculate_hit_point(*ray, t);
	base_to_intersection = get_vector_two_point(cylinder.coordinate, intersection_point);
	return vector_dot(base_to_intersection, cylinder.vector);
}

t_hit_cylinder	hit_cylinder(t_cylinder cylinder, t_ray *ray)
{
	t_hit_cylinder	hit;

	hit.oc = get_vector_two_point(cylinder.coordinate, ray->origin);
	hit.k = vector_dot(ray->direction, cylinder.vector);
	hit.a = vector_dot(ray->direction, ray->direction) - pow(hit.k, 2);
	hit.b = 2.0 * (vector_dot(ray->direction, hit.oc) - \
		hit.k * vector_dot(hit.oc, cylinder.vector));
	hit.c = vector_dot(hit.oc, hit.oc) - pow(vector_dot(hit.oc, \
		cylinder.vector), 2) - pow(cylinder.diameter / 2, 2);
	hit.discriminant = pow(hit.b, 2) - 4 * hit.a * hit.c;
	hit.t_1 = quadratic_equation_1(hit.a, hit.b, hit.c);
	hit.t_2 = quadratic_equation_2(hit.a, hit.b, hit.c);
	hit.base = get_hit_base(ray, cylinder, hit.t_1);
	hit.top = get_hit_top(ray, cylinder, hit.t_2);
	return (hit);
}

int is_hit_point_between_top_and_bottom(double hit_base, double hit_top, double height)
{
	if ((hit_base >= 0 && hit_base <= height) || (hit_top >= 0 && hit_top <= height))
		return (1);
	return (0);
}

t_coordinate	get_closer_cylinder_point(t_cylinder cylinder, t_ray *ray)
{
	t_coordinate	hit_point;
	t_hit_cylinder	info;

	hit_point = init_hit_point();
	info = hit_cylinder(cylinder, ray);
	if (info.t_1 < 0 && info.t_2 < 0)
		return (hit_point);
	hit_point = get_closer_hit_point(info.t_1, info.t_2, *ray);
	if (!is_hit_point_between_top_and_bottom(info.base, info.top, cylinder.height))
		return (init_hit_point());
	return (hit_point);
}