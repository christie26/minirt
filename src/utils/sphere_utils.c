#include "../../includes/minirt.h"
#include "../../includes/utils.h"

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
	c = vector_dot(ray.direction, ray.direction) - sphere.diameter / 2 * sphere.diameter / 2;
	discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}

t_coordinate get_hit_point_sphere(t_sphere sphere, t_ray ray)
{
	t_coordinate	hit_point_1;
	t_coordinate	hit_point_2;
	t_vector		dif;
	double			a;
	double			b;
	double			c;
	double			t_1;
	double			t_2;

	dif = get_vector_two_point(ray.origin, sphere.center);
	a = vector_dot(ray.direction, ray.direction);
	b = 2 * vector_dot(dif, ray.direction);
	c = vector_dot(ray.direction, ray.direction) - sphere.diameter / 2 * sphere.diameter / 2;
	t_1 = quadratic_equation_1(a, b, c);
	t_2 = quadratic_equation_2(a, b, c);
	hit_point_1 = calculate_hit_point(ray, t_1);
	hit_point_2 = calculate_hit_point(ray, t_2);
	if (get_distance(ray.origin, hit_point_1) < get_distance(ray.origin, hit_point_2))
		return(hit_point_1);
	return (hit_point_2);
}
