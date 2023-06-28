#include "../../includes/minirt.h"

t_coordinate get_sphere_point(t_sphere sphere, t_ray ray)
{
	t_vector		dif;
	double			a;
	double			b;
	double			c;

	dif = get_vector_of_two_point(sphere.center, ray.origin);
	a = vector_dot(ray.direction, ray.direction);
	b = 2 * vector_dot(dif, ray.direction);
	c = vector_dot(dif, dif) - pow(sphere.diameter / 2, 2);
	return (get_closer_hit_point(a, b, c, ray));
}
