
#include "../../includes/minirt.h"

int	hit_plane(t_plane plane, t_ray ray)
{
	t_vector	plane_to_ray;
	double		t;
	double		denom;

	denom = vector_dot(ray.direction, plane.vector);
	if (fabs(denom) < 1e-6)
		return (NONE);
	plane_to_ray = get_vector_two_point(plane.coordinate, ray.origin);
	t = vector_dot(plane_to_ray, plane.vector) / denom;
	if (t < 0)
		return (NONE);
	return (PLANE);
}

int is_parallel(t_vector vector1, t_vector vector2, double *dot_product)
{
	*dot_product = vector_dot(vector1, vector2);
	if (fabs(*dot_product) < 1e-6)
		return (1);
	return (0);
}

t_coordinate	get_closer_plane_point(t_plane plane, t_ray *ray)
{
	t_coordinate	hit_point;
	double			denominator;
	double			t;
	t_vector		ray_to_plane;

	hit_point = init_hit_point();
	if (is_parallel(plane.vector, ray->direction, &denominator))
		return (hit_point);
	ray_to_plane = get_vector_two_point(ray->origin, plane.coordinate);
	t = vector_dot(plane.vector, ray_to_plane) / denominator;
	if (t >= 0)
		hit_point = calculate_hit_point(*ray, t);
	return (hit_point);
}