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
	// c = vector_dot(ray.direction, ray.direction) - sphere.diameter / 2 * sphere.diameter / 2;
	discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}

t_coordinate get_sphere_point(t_sphere sphere, t_ray ray)
{
	t_coordinate	hit_point_1;
	t_coordinate	hit_point_2;
	t_vector		dif;
	double			a;
	double			b;
	double			c;
	double			t_1;
	double			t_2;
	// double 			t;


	dif = get_vector_two_point(ray.origin, sphere.center);
	a = vector_dot(ray.direction, ray.direction);
	b = 2 * vector_dot(dif, ray.direction);
	c = vector_dot(dif, dif) - pow(sphere.diameter / 2, 2);
	// c = vector_dot(ray.direction, ray.direction) - sphere.diameter / 2 * sphere.diameter / 2;
	t_1 = quadratic_equation_1(a, b, c);
	t_2 = quadratic_equation_2(a, b, c);
	// printf("t_1: %f\n", t_1);
	// printf("t_2: %f\n", t_2);
	// if (t_1 < 0 && t_2 < 0)
	// 	return (ray.origin);
	// if (t_1 < t_2)
	// 	t = t_1;
	// else
	// 	t = t_2;
	// return (calculate_hit_point(ray, t));
	hit_point_1 = calculate_hit_point(ray, t_1);
	hit_point_2 = calculate_hit_point(ray, t_2);
	if (get_distance(ray.origin, hit_point_1) < get_distance(ray.origin, hit_point_2))
		return(hit_point_1);
	return (hit_point_2);
}