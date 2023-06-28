
#include "../../includes/minirt.h"

int	hit_sphere(t_sphere sphere, t_ray ray)
{
	t_vector	dif;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	dif = get_vector_of_two_point(sphere.center, ray.origin);
	a = vector_dot(ray.direction, ray.direction);
	b = 2 * vector_dot(dif, ray.direction);
	c = vector_dot(dif, dif) - pow(sphere.diameter / 2, 2);
	discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}

int	hit_plane(t_plane plane, t_ray ray)
{
	t_vector	plane_to_ray;
	double		t;
	double		denom;

	denom = vector_dot(ray.direction, plane.vector);
	if (fabs(denom) < 1e-6)
		return (NONE);
	plane_to_ray = get_vector_of_two_point(plane.coordinate, ray.origin);
	t = vector_dot(plane_to_ray, plane.vector) / denom;
	if (t < 0)
		return (NONE);
	return (PLANE);
}
