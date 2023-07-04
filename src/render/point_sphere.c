#include "../../includes/minirt.h"

t_hit_sphere	hit_sphere(t_sphere sphere, t_ray ray)
{
	t_hit_sphere	hit;

	hit.dif = get_vector_two_point(sphere.center, ray.origin);
	hit.a = vector_dot(ray.direction, ray.direction);
	hit.b = 2 * vector_dot(hit.dif, ray.direction);
	hit.c = vector_dot(hit.dif, hit.dif) - pow(sphere.diameter / 2, 2);
	hit.discriminant = hit.b * hit.b - 4 * hit.a * hit.c;
	hit.t_1 = quadratic_equation_1(hit.a, hit.b, hit.c);
	hit.t_2 = quadratic_equation_2(hit.a, hit.b, hit.c);
	return (hit);
}

// t_coordinate get_closer_hit_point(double t_1, double t_2, t_ray ray)
// {
// 	t_coordinate closer_hit_point;

// 	closer_hit_point = get_closer_point(calculate_hit_point(ray, t_1), calculate_hit_point(ray, t_2), ray);
// 	return (closer_hit_point);
// }

// t_coordinate get_closer_hit_point(double a, double b, double c, t_ray ray)
// {
// 	double t_1;
// 	double t_2;
// 	t_coordinate closer_hit_point;

// 	t_1 = quadratic_equation_1(a, b, c);
// 	t_2 = quadratic_equation_2(a, b, c);
// 	closer_hit_point = get_closer_point(calculate_hit_point(ray, t_1), calculate_hit_point(ray, t_2), ray);
// 	return (closer_hit_point);
// }

t_coordinate	get_closer_sphere_point(t_sphere sphere, t_ray *ray)
{
	t_coordinate	hit_point;
	t_hit_sphere	info;

	hit_point.x = INFINITY;
	hit_point.y = INFINITY;
	hit_point.z = INFINITY;
	info = hit_sphere(sphere, *ray);
	if (info.t_1 < 0 && info.t_2 < 0)
		return (hit_point);
	hit_point = get_closer_hit_point(info.t_1, info.t_2, *ray);
	return (hit_point);
}
