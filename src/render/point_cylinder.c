#include "../../includes/minirt.h"

double	border_check(t_ray ray, t_cylinder cylinder, double t)
{
	t_coordinate	intersection_point;
	t_vector		base_to_intersection;

	intersection_point = calculate_hit_point(ray, t);
	base_to_intersection = get_vector_two_point(cylinder.base, \
			intersection_point);
	return (vector_dot(base_to_intersection, cylinder.vector));
}

t_hit_cylinder	hit_cylinder(t_cylinder cylinder, t_ray *ray)
{
	t_hit_cylinder	hit;

	hit.oc = get_vector_two_point(cylinder.base, ray->origin);
	hit.k = vector_dot(ray->direction, cylinder.vector);
	hit.a = vector_dot(ray->direction, ray->direction) - pow(hit.k, 2);
	hit.b = 2.0 * (vector_dot(ray->direction, hit.oc) - hit.k
			* vector_dot(hit.oc, cylinder.vector));
	hit.c = vector_dot(hit.oc, hit.oc) - pow(vector_dot(hit.oc,
				cylinder.vector), 2) - pow(cylinder.diameter / 2, 2);
	hit.discriminant = pow(hit.b, 2) - 4 * hit.a * hit.c;
	hit.t_1 = quadratic_equation_1(hit.a, hit.b, hit.c);
	hit.t_2 = quadratic_equation_2(hit.a, hit.b, hit.c);
	return (hit);
}

t_coordinate	hit_cylinder_lid(t_cylinder cylinder, t_ray *ray,
		t_coordinate base_center, t_coordinate top_center)
{
	t_coordinate	result;
	double			t1;
	double			t2;
	t_coordinate	hit_point1;
	t_coordinate	hit_point2;

	t1 = vector_dot(cylinder.vector, get_vector_two_point(ray->origin, \
				base_center)) / vector_dot(ray->direction, cylinder.vector);
	t2 = vector_dot(cylinder.vector, get_vector_two_point(ray->origin, \
				top_center)) / vector_dot(ray->direction, cylinder.vector);
	hit_point1 = calculate_hit_point(*ray, t1);
	if (get_distance(hit_point1, base_center) > cylinder.diameter / 2 || t1 < 0)
		hit_point1 = init_hit_point();
	hit_point2 = calculate_hit_point(*ray, t2);
	if (get_distance(hit_point2, top_center) > cylinder.diameter / 2 || t2 < 0)
		hit_point2 = init_hit_point();
	result = get_closer_point(hit_point2, hit_point1, *ray);
	return (result);
}

t_coordinate	get_side_point(t_hit_cylinder info, t_ray ray, \
		t_cylinder cylinder, double height)
{
	double			check_1;
	double			check_2;
	t_coordinate	point_1;
	t_coordinate	point_2;

	check_1 = border_check(ray, cylinder, info.t_1);
	check_2 = border_check(ray, cylinder, info.t_2);
	point_1 = init_hit_point();
	if (check_1 >= 0 && check_1 <= height && info.t_1 > 0)
		point_1 = calculate_hit_point(ray, info.t_1);
	point_2 = init_hit_point();
	if (check_2 >= 0 && check_2 <= height && info.t_2 > 0)
		point_2 = calculate_hit_point(ray, info.t_2);
	point_1 = get_closer_point(point_1, point_2, ray);
	return (point_1);
}

t_coordinate	get_closer_cylinder_point(t_cylinder cylinder, t_ray *ray)
{
	t_coordinate	side_point;
	t_coordinate	hit_point;
	t_coordinate	lid_point;
	t_hit_cylinder	info;

	hit_point = init_hit_point();
	side_point = init_hit_point();
	lid_point = hit_cylinder_lid(cylinder, ray, cylinder.top, cylinder.base);
	info = hit_cylinder(cylinder, ray);
	if (info.discriminant > 0 && (info.t_1 > 0 || info.t_2 > 0))
		side_point = get_side_point(info, *ray, cylinder, cylinder.height);
	hit_point = get_closer_point(side_point, lid_point, *ray);
	if (hit_point.x != INFINITY)
		ray->hit_normal = get_cylinder_normal(cylinder, hit_point);
	return (hit_point);
}
