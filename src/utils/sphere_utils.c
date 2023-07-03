#include "../../includes/minirt.h"

int shadow_sphere(t_sphere sphere, t_ray ray)
{
    t_vector dif;
	double	a;
	double	b;
	double	c;
	double t_1;
	double t_2;

	dif = get_vector_two_point(sphere.center, ray.origin);
	a = vector_dot(ray.direction, ray.direction);
	b = 2 * vector_dot(dif, ray.direction);
	c = vector_dot(dif, dif) - pow(sphere.diameter / 2, 2);
	t_1 = quadratic_equation_1(a, b, c);
	t_2 = quadratic_equation_2(a, b, c);
	return (t_1 > 0 || t_2 > 0);
}

t_coordinate	get_closer_point(t_coordinate hit_point_1, t_coordinate hit_point_2, t_ray ray)
{
	if (get_distance(ray.origin, hit_point_1) < get_distance(ray.origin, hit_point_2))
		return(hit_point_1);
	return (hit_point_2);
}

t_coordinate get_closer_hit_point(double t_1, double t_2, t_ray ray)
{
	t_coordinate closer_hit_point;

	closer_hit_point = get_closer_point(calculate_hit_point(ray, t_1), calculate_hit_point(ray, t_2), ray);
	return (closer_hit_point);
}
