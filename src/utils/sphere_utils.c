#include "../../includes/minirt.h"

int hit_sphere(t_sphere sphere, t_ray ray)
{
    t_vector dif;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	dif = get_vector_two_point(ray.origin, sphere.center);
	a = vector_dot(ray.direction, ray.direction);
	b = 2 * vector_dot(dif, ray.direction);
	c = vector_dot(dif, dif) - pow(sphere.diameter / 2, 2);
	discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}

static t_coordinate	get_closer_point(t_coordinate hit_point_1, t_coordinate hit_point_2, t_ray ray)
{
	if (get_distance(ray.origin, hit_point_1) < get_distance(ray.origin, hit_point_2))
		return(hit_point_1);
	return (hit_point_2);
}

static t_coordinate get_closer_hit_point(double a, double b, double c, t_ray ray)
{
	double t_1;
	double t_2;
	t_coordinate closer_hit_point;

	t_1 = quadratic_equation_1(a, b, c);
	t_2 = quadratic_equation_2(a, b, c);
	closer_hit_point = get_closer_point(calculate_hit_point(ray, t_1), calculate_hit_point(ray, t_2), ray);
	return (closer_hit_point);
}

t_coordinate get_sphere_point(t_sphere sphere, t_ray ray)
{
	t_vector		dif;
	double			a;
	double			b;
	double			c;

	dif = get_vector_two_point(ray.origin, sphere.center);
	a = vector_dot(ray.direction, ray.direction);
	b = 2 * vector_dot(dif, ray.direction);
	c = vector_dot(dif, dif) - pow(sphere.diameter / 2, 2);
	return (get_closer_hit_point(a, b, c, ray));
}
