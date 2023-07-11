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

t_color	get_checkerboard_cylinder(t_cylinder cylinder, t_coordinate hit_point)
{
	double			a;
	double			b;
	double			c;
	double			d;
	double			height;
	t_vector		vector;
	t_vector		vertical;
	t_coordinate	center;
	t_coordinate	new_center;
	t_vector		new_vector;
	double			angle;
	
	vector = cylinder.vector;
	center = cylinder.base;
	a = vector.x;
	b = vector.y;
	c = vector.z;
	d = - vector.x * hit_point.x - vector.y * hit_point.y - vector.z * hit_point.z;
	height = fabs(a * center.x + b * center.y + c * center.z + d) / sqrt(a * a + b * b + c * c);
	
	new_center.x = center.x + vector.x * height;
	new_center.y = center.y + vector.y * height;
	new_center.z = center.z + vector.z * height;

	if (!cylinder.checker)
		return (cylinder.color);
	new_vector = vector_unit(get_vector_two_point(new_center, hit_point));
	vertical = vector_unit(get_world_vertical(vector));
	angle = radian_to_degree(acos(vector_dot(vertical, new_vector)));
	// angle = radian_to_degree(asin(vector_length(vector_cross(vertical, new_vector))));

	if (!cylinder.checker)
		return (cylinder.color);
	// if (fabs(height - cylinder.height / 2) < 0.0001)
	// {
	// 	printf("new_vector = (%.2f,%.2f,%.2f)\n", new_vector.x,new_vector.y,new_vector.z);
	// 	printf("vertical = (%.2f,%.2f,%.2f)\n", vertical.x,vertical.y,vertical.z);
	// 	printf("angle = %.2f\n", angle);
	// }
	if (((int)angle / 15) & 1)
	{
		// if (dmod(height, 1) > 0 && dmod(height, 1) < 0.5)
		// 	return (cylinder.color);
		// else
			return (get_color("0,0,0"));
	}
	else
	{
		// if (dmod(height, 1) > 0 && dmod(height, 1) < 0.5)
		// 	return (get_color("0,0,0"));
		// else
			return (cylinder.color);
	}
}
