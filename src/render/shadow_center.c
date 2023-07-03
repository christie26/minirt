#include "../../includes/minirt.h"

int	blocked_plane(t_plane plane, t_ray ray)
{
	t_vector	ray_to_plane;
	double		denominator;
	double		t;

	ray_to_plane = vector_sub(init_vector(ray.origin.x, ray.origin.y, ray.origin.z), \
		init_vector(plane.coordinate.x, plane.coordinate.y, plane.coordinate.y));
	if (is_parallel(plane.vector, ray.direction, &denominator))
		return (0);
	t = vector_dot(ray_to_plane, plane.vector) / denominator;
	if (t < 0 || t > 1)
		return (0);
	return (1);
}

int blocked_sphere(t_sphere sphere, t_ray ray)
{
    t_vector dif;
	double	a;
	double	b;
	double	c;
	double t_1;
	double t_2;

	dif = get_vector_two_point(sphere.center, ray.origin);
	a = vector_dot(ray.direction, ray.direction);
	b = 2 * vector_dot(dif, ray.direction);
	c = vector_dot(dif, dif) - pow(sphere.diameter / 2, 2);
	t_1 = quadratic_equation_1(a, b, c);
	t_2 = quadratic_equation_2(a, b, c);
	return (t_1 > 0 || t_2 > 0);
}

int	is_shadow(t_data data, t_ray hit_to_light)
{
	t_node *object;
	t_coordinate hit_point;

	object = data.object_list->headnode;
	hit_point = hit_to_light.origin;

	while (object)
	{
		if (object->type == SPHERE)
		{
			if (blocked_sphere(*(t_sphere *)object, hit_to_light))
			{
				printf("blocked by sphere\n");
				return (1);
			}
		}
		else
		{
			if (blocked_plane(*(t_plane *)object, hit_to_light))
			{
				printf("blocked by plane\n");
				return (1);
			}
		}
		object = object->next;
	}
	return (0);
}