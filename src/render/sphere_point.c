#include "../../includes/minirt.h"

t_hit_sphere	hit_sphere(t_sphere sphere, t_ray ray)
{
	t_hit_sphere	hit;

	hit.dif = get_vector_two_point(sphere.center, ray.origin);
	hit.a = vector_dot(ray.direction, ray.direction);
	hit.b = 2 * vector_dot(hit.dif, ray.direction);
	hit.c = vector_dot(hit.dif, hit.dif) - pow(sphere.diameter / 2, 2);
	hit.discriminant = hit.b * hit.b - 4 * hit.a * hit.c;
	return (hit);
}

t_coordinate	get_closer_sphere_point(t_sphere sphere, t_ray ray)
{
	t_coordinate	hit_point;
	t_hit_sphere	info;

	info = hit_sphere(sphere, ray);
	hit_point = get_closer_hit_point(info.a, info.b, info.c, ray);
	return (hit_point);
}
