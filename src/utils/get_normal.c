/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:50:56 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:50:56 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_vector	get_sphere_normal(t_sphere sphere, t_coordinate hit_point)
{
	t_vector	normal;

	normal = vector_unit(get_vector_two_point(sphere.center, hit_point));
	return (normal);
}

static t_vector	get_plane_normal(t_plane plane, t_coordinate hit_point)
{
	t_vector	normal;

	normal = vector_unit(plane.vector);
	(void)hit_point;
	return (normal);
}

static t_vector	get_cylinder_normal(t_cylinder cylinder, t_coordinate hit_point)
{
	t_vector	normal;
	t_vector	v;
	t_vector	p;

	if (fabs(vector_dot(get_vector_two_point(hit_point, cylinder.base), \
			cylinder.vector)) < EPSILON)
		normal = vector_mult_scalar(cylinder.vector, -1);
	else if (fabs(vector_dot(get_vector_two_point(hit_point, cylinder.top), \
				cylinder.vector)) < EPSILON)
		normal = cylinder.vector;
	else
	{
		v = get_vector_two_point(cylinder.base, hit_point);
		p = vector_add(cord_to_vec(cylinder.base),
				vector_mult_scalar(cylinder.vector, vector_dot(v, \
						cylinder.vector)));
		normal = vector_unit(vector_sub(init_vector(hit_point.x, hit_point.y, \
						hit_point.z), p));
	}
	return (normal);
}

t_vector	get_normal(void *object, t_coordinate hit_point, int type)
{
	t_vector	normal;

	if (type == SPHERE)
		normal = get_sphere_normal(*(t_sphere *)object, hit_point);
	else if (type == PLANE)
		normal = get_plane_normal(*(t_plane *)object, hit_point);
	else
		normal = get_cylinder_normal(*(t_cylinder *)object, hit_point);
	return (normal);
}
