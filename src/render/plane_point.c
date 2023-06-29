
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
