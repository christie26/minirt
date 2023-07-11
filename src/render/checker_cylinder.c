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
	const t_vector	base_vec = cord_to_vec(cylinder.base);

	d = (-1) * vector_dot(cylinder.vector, hit_vector);
	height = fabs(vector_dot(cylinder.vector, base_vec) + d) \
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

static double	get_angle(t_cylinder cylinder, t_vector new_vector)
{
	const t_vector		vertical = get_world_vertical(cylinder.vector);
	const t_vector		horizontal = vector_cross(cylinder.vector, vertical);
	double				angle;
	double				angle2;

	angle = radian_to_degree(acos(vector_dot(vertical, new_vector)));
	angle2 = radian_to_degree(acos(vector_dot(horizontal, new_vector)));
	if (angle2 > 90)
		angle *= -1;
	angle += 180;
	return (angle);
}

t_color	get_checkerboard_cylinder(t_cylinder cylinder, t_coordinate hit_point)
{
	const double		height = get_height(cylinder, hit_point);
	double				angle;
	t_coordinate		new_base;
	t_vector			new_vector;

	new_base = get_new_base(cylinder, height);
	new_vector = vector_unit(get_vector_two_point(new_base, hit_point));
	angle = get_angle(cylinder, new_vector);
	if (!cylinder.checker)
		return (cylinder.color);
	if (((int)angle / 15) & 1)
	{
		if (fmod(height, 1) > 0 && fmod(height, 1) < 0.5)
			return (cylinder.color);
		else
			return (get_color("0,0,0"));
	}
	else
	{
		if (fmod(height, 1) > 0 && fmod(height, 1) < 0.5)
			return (get_color("0,0,0"));
		else
			return (cylinder.color);
	}
}
