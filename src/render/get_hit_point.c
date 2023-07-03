#include "../../includes/minirt.h"

int is_parallel(t_vector vector1, t_vector vector2, double *dot_product)
{
	*dot_product = vector_dot(vector1, vector2);
	if (fabs(*dot_product) < 1e-6)
		return (1);
	return (0);
}

static t_coordinate	get_closer_plane_point(t_plane plane, t_ray *ray)
{
	t_coordinate	hit_point;
	double			denominator;
	double			t;
	t_vector		ray_to_plane;

	hit_point.x = INFINITY;
	hit_point.y = INFINITY;
	hit_point.z = INFINITY;
	if (is_parallel(plane.vector, ray->direction, &denominator))
		return (hit_point);
	ray_to_plane = get_vector_two_point(ray->origin, plane.coordinate);
	t = vector_dot(plane.vector, ray_to_plane) / denominator;
	if (t >= 0)
		hit_point = calculate_hit_point(*ray, t);
	return (hit_point);
}

t_coordinate	get_hit_point(t_ray *ray, t_node *node)
{
	t_coordinate hit_point;
	void *object;

	object = node->object;
	if (node->type == SPHERE)
		hit_point = get_closer_sphere_point(*(t_sphere *)object, ray);
	else
		hit_point = get_closer_plane_point(*(t_plane *)object, ray);
	return (hit_point);
}