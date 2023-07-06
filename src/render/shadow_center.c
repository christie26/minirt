#include "../../includes/minirt.h"

void	fix_hit_to_light(t_ray *hit_to_light)
{
	hit_to_light->origin.x = hit_to_light->origin.x + 0.1 *  hit_to_light->direction.x;
	hit_to_light->origin.y = hit_to_light->origin.y + 0.1 *  hit_to_light->direction.y;
	hit_to_light->origin.z = hit_to_light->origin.z + 0.1 *  hit_to_light->direction.z;
}

static int	blocked_plane(t_plane plane, t_ray hit_to_light)
{
	t_vector	ray_to_plane;
	double		denominator;
	double		t;

	ray_to_plane = get_vector_two_point(hit_to_light.origin, plane.coordinate);
	if (is_parallel(plane.vector, hit_to_light.direction, &denominator))
		return (0);
	t = vector_dot(ray_to_plane, plane.vector) / denominator;
	return (t >= 0);
}

int blocked_sphere(t_sphere sphere, t_ray hit_to_light)
{
	t_hit_sphere	info;

	info = hit_sphere(sphere, hit_to_light);
	return (info.t_1 > 0 || info.t_2 > 0);
}

static int blocked_cylinder(t_cylinder cylinder, t_ray hit_to_light)
{
	t_hit_cylinder	info;
	t_coordinate	hit_point;
	t_coordinate	lid_point;
	t_coordinate	init_point;

	info = hit_cylinder(cylinder, &hit_to_light);
	init_point = init_hit_point();
	hit_point = init_hit_point();
	if (info.t_1 < 0 && info.t_2 < 0)
	{
		lid_point = hit_cylinder_lid(cylinder, &hit_to_light, cylinder.top, cylinder.base);
		if (is_same_coordinate(lid_point, init_point))
			return (0);
		return (1);
	}
	else
	{
		hit_point = get_closer_hit_point(info.t_1, info.t_2, hit_to_light);
		lid_point = hit_cylinder_lid(cylinder, &hit_to_light, cylinder.top, cylinder.base);
		hit_point = get_closer_point(hit_point, lid_point, hit_to_light);
	}
	if (!is_hit_point_between_top_and_bottom(info.base, info.top, cylinder.height))
	{
		if (is_same_coordinate(lid_point, init_point))
			return (0);
	}
	// printf("hit_point: %f, %f, %f\n", hit_to_light.hit_point.x, hit_to_light.hit_point.y, hit_to_light.hit_point.z);
	return (1);
}

static int blocked_paraboloid(t_paraboloid paraboloid, t_ray hit_to_light)
{
	t_hit_paraboloid	info;

	info = hit_paraboloid(paraboloid, &hit_to_light);
	if (info.t_1 < 0 && info.t_2 < 0)
		return (0);
	if ((info.base >= 0 && info.base <= paraboloid.height) || (info.top >= 0 && info.top <= paraboloid.height))
		return (0);
	return (1);
}

int	is_shadow(t_data data, t_ray hit_to_light)
{
	t_node			*node;
	void			*object;

	node = data.object_list->headnode;
	while (node)
	{
		object = node->object;
		if (node->type == SPHERE)
		{
			if (blocked_sphere(*(t_sphere *)object, hit_to_light))
				return (1);
		}
		else if (node->type == PLANE)
		{
			if (blocked_plane(*(t_plane *)object, hit_to_light))
				return (1);
		}
		else if (node->type == CYLINDER)
		{
			if (blocked_cylinder(*(t_cylinder *)object, hit_to_light))
				return (1);
		}
		else if (node->type == PARABOLOID)
		{
			if (blocked_paraboloid(*(t_paraboloid *)object, hit_to_light))
				return (1);
		}
		node = node->next;
	}
	return (0);
}