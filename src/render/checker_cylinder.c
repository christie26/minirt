/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:49:57 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:50:01 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static double	get_height(t_cylinder cylinder, t_coordinate hit_point)
{
	double			d;
	double			height;
	const t_vector	hit_vector = cord_to_vec(hit_point);
	const t_vector	center_vec = cord_to_vec(cylinder.base);

	d = (-1) * vector_dot(cylinder.vector, hit_vector);
	height = fabs(vector_dot(cylinder.vector, center_vec) + d) \
			/ sqrt(vector_dot(cylinder.vector, cylinder.vector));
	return (height);
}

static t_coordinate	get_new_base(t_cylinder cylinder, double height)
{
	t_coordinate	new_base;

	new_base.x = cylinder.base.x + cylinder.vector.x * height;
	new_base.y = cylinder.base.y + cylinder.vector.y * height;
	new_base.z = cylinder.base.z + cylinder.vector.z * height;
	return (new_base);
}

t_color	get_checkerboard_cylinder(t_cylinder cylinder, t_coordinate hit_point)
{
	const double		height = get_height(cylinder, hit_point);
	const t_coordinate	new_base = get_new_base(cylinder, height);
	const t_vector		vertical = get_world_vertical(cylinder.vector);
	const t_vector		new_vector = get_vector_two_point(new_base, hit_point);
	const double		angle = radian_to_degree(acos(vector_dot(vertical, \
							new_vector)));

	if (!cylinder.checker)
		return (cylinder.color);
	if (((int)angle / 15) & 1)
	{
		if (dmod(height, 1) > 0 && dmod(height, 1) < 0.5)
			return (cylinder.color);
		else
			return (get_color("0,0,0"));
	}
	else
	{
		if (dmod(height, 1) > 0 && dmod(height, 1) < 0.5)
			return (get_color("0,0,0"));
		else
			return (cylinder.color);
	}
}
