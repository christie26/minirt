/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocked_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:50:03 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:50:03 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	blocked_plane(t_plane plane, t_ray hit_to_light)
{
	t_vector		ray_to_plane;
	double			denominator;
	double			t;
	double			t_of_light;

	ray_to_plane = get_vector_two_point(hit_to_light.origin, plane.coordinate);
	if (is_parallel(plane.vector, hit_to_light.direction, &denominator))
		return (0);
	t = vector_dot(ray_to_plane, plane.vector) / denominator;
	t_of_light = vector_length(get_vector_two_point(hit_to_light.origin, \
				hit_to_light.light)) / vector_length(hit_to_light.direction);
	return (t >= 0 && t <= t_of_light);
}

int	blocked_sphere(t_sphere sphere, t_ray hit_to_light)
{
	t_hit_sphere	info;
	double			t_of_light;

	info = hit_sphere(sphere, hit_to_light);
	t_of_light = vector_length(get_vector_two_point(hit_to_light.origin, \
				hit_to_light.light)) / vector_length(hit_to_light.direction);
	if (info.discriminant < 0)
		return (0);
	return ((info.t_1 > 0 && info.t_1 <= t_of_light + EPSILON) || \
			(info.t_2 > 0 && info.t_2 <= t_of_light + EPSILON));
}

int	blocked_cylinder(t_cylinder cylinder, t_ray hit_to_light)
{
	t_coordinate	hit_point;
	double			t_of_light;
	double			t_of_hit;

	hit_point = get_closer_cylinder_point(cylinder, &hit_to_light);
	if (hit_point.x == INFINITY && hit_point.y == INFINITY && hit_point.z == INFINITY)
		return (0);
	t_of_light = vector_length(get_vector_two_point(hit_to_light.origin, \
				hit_to_light.light)) / vector_length(hit_to_light.direction);
	t_of_hit = vector_length(get_vector_two_point(hit_to_light.origin, \
				hit_point)) / vector_length(hit_to_light.direction);
	return (t_of_hit <= t_of_light + EPSILON);
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
