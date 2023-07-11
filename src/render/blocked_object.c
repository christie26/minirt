#include "../../includes/minirt.h"

int	blocked_plane(t_plane plane, t_ray hit_to_light)
{
	t_vector		ray_to_plane;
	double			denominator;
	double			t;
	double			distance;
	t_coordinate	calculated_light_point;

	ray_to_plane = get_vector_two_point(hit_to_light.origin, plane.coordinate);
	if (is_parallel(plane.vector, hit_to_light.direction, &denominator))
		return (0);
	t = vector_dot(ray_to_plane, plane.vector) / denominator;
	distance = get_distance(hit_to_light.origin, hit_to_light.light);
	calculated_light_point = calculate_hit_point(hit_to_light, t);
	return (t >= 0 && distance > get_distance(hit_to_light.origin, calculated_light_point));
}

int	blocked_sphere(t_sphere sphere, t_ray hit_to_light)
{
	t_hit_sphere	info;

	info = hit_sphere(sphere, hit_to_light);
	if (info.discriminant < 0)
		return (0);
	return (info.t_1 > 0 || info.t_2 > 0);
}

int	blocked_cylinder(t_cylinder cylinder, t_ray hit_to_light)
{
	t_coordinate	hit_point;

	hit_point = get_closer_cylinder_point(cylinder, &hit_to_light);
	if (hit_point.x == INFINITY && hit_point.y == INFINITY && hit_point.z == INFINITY)
		return (0);
	return (1);
}

int	blocked_paraboloid(t_paraboloid paraboloid, t_ray hit_to_light)
{
	t_hit_paraboloid	info;

	info = hit_paraboloid(paraboloid, &hit_to_light);
	if (info.t_1 < 0 && info.t_2 < 0)
		return (0);
	if ((info.base >= 0 && info.base <= paraboloid.height) || (info.top >= 0
			&& info.top <= paraboloid.height))
		return (0);
	return (1);
}
