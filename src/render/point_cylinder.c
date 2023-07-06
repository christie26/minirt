#include "../../includes/minirt.h"

double border_check(t_ray *ray, t_cylinder cylinder, double t)
{
	t_coordinate	intersection_point;
	t_vector		base_to_intersection;

	intersection_point = calculate_hit_point(*ray, t);
	base_to_intersection = get_vector_two_point(cylinder.base, intersection_point);
	return vector_dot(base_to_intersection, cylinder.vector);
}

t_hit_cylinder	hit_cylinder(t_cylinder cylinder, t_ray *ray)
{
	t_hit_cylinder	hit;

	hit.oc = get_vector_two_point(cylinder.base, ray->origin);
	hit.k = vector_dot(ray->direction, cylinder.vector);
	
	hit.a = vector_dot(ray->direction, ray->direction) - pow(hit.k, 2);
	hit.b = 2.0 * (vector_dot(ray->direction, hit.oc) - hit.k * vector_dot(hit.oc, cylinder.vector));
	hit.c = vector_dot(hit.oc, hit.oc) - pow(vector_dot(hit.oc, cylinder.vector), 2) - pow(cylinder.diameter / 2, 2);
	
	hit.discriminant = pow(hit.b, 2) - 4 * hit.a * hit.c;
	hit.t_1 = quadratic_equation_1(hit.a, hit.b, hit.c);
	hit.t_2 = quadratic_equation_2(hit.a, hit.b, hit.c);
	hit.base = border_check(ray, cylinder, hit.t_1);
	hit.top = border_check(ray, cylinder, hit.t_2);
	return (hit);
}

int is_hit_point_between_top_and_bottom(double hit_base, double hit_top, double height)
{
	if ((hit_base >= 0 && hit_base <= height) || (hit_top >= 0 && hit_top <= height))
		return (1);
	return (0);
}

t_coordinate hit_cylinder_lid(t_cylinder cylinder, t_ray *ray, t_coordinate top_center, t_coordinate base_center)
{
	double			t1, t2;
	t_coordinate	hit_point1, hit_point2;

	t1 = vector_dot(vector_unit(cylinder.vector), get_vector_two_point(ray->origin, base_center))
		/ vector_dot(ray->direction, vector_unit(cylinder.vector));
	t2 = vector_dot(vector_unit(cylinder.vector), get_vector_two_point(ray->origin, top_center))
		/ vector_dot(ray->direction, vector_unit(cylinder.vector));
	hit_point1 = calculate_hit_point(*ray, t1);
	hit_point2 = calculate_hit_point(*ray, t2);
	if (get_distance(hit_point1, base_center) > cylinder.diameter / 2 || t1 <= 0)
		hit_point1 = init_hit_point();
	if (get_distance(hit_point2, top_center) > cylinder.diameter / 2 || t2 <= 0) 
		hit_point2 = init_hit_point();
	return get_closer_point(hit_point1, hit_point2, *ray);
}


t_coordinate	get_closer_cylinder_point(t_cylinder cylinder, t_ray *ray)
{
	t_coordinate	hit_point;
	t_coordinate	lid_point;
	t_hit_cylinder	info;

	hit_point = init_hit_point();
	info = hit_cylinder(cylinder, ray);
	if (info.t_1 < 0 && info.t_2 < 0)
	{
		hit_point = hit_cylinder_lid(cylinder, ray, cylinder.top, cylinder.base);
		if (hit_point.x == INFINITY && hit_point.y == INFINITY && hit_point.z == INFINITY)
			return (hit_point);
	}
	else
	{
		hit_point = get_closer_hit_point(info.t_1, info.t_2, *ray);
		lid_point = hit_cylinder_lid(cylinder, ray, cylinder.top, cylinder.base);
		hit_point = get_closer_point(hit_point, lid_point, *ray);
		// return (hit_point);
	}
	if (!is_hit_point_between_top_and_bottom(info.base, info.top, cylinder.height))
	{
		hit_point = hit_cylinder_lid(cylinder, ray, cylinder.top, cylinder.base);
		if (hit_point.x == INFINITY && hit_point.y == INFINITY && hit_point.z == INFINITY)
			return (init_hit_point());
	}
	hit_point = hit_cylinder_lid(cylinder, ray, cylinder.top, cylinder.base);
	if (hit_point.x == INFINITY && hit_point.y == INFINITY && hit_point.z == INFINITY)
		return (hit_point);
	return (hit_point);
}