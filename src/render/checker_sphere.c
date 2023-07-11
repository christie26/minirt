/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:49:55 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:49:55 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_color	which_color(t_color color, double xy_angle, double z_angle)
{
	if (fmod(xy_angle, 30) > 0 && fmod(xy_angle, 30) < 15)
	{
		if (fmod(z_angle, 30) > 0 && fmod(z_angle, 30) < 15)
			return (color);
		else
			return (get_color("0,0,0"));
	}
	else
	{
		if (fmod(z_angle, 30) > 0 && fmod(z_angle, 30) < 15)
			return (get_color("0,0,0"));
		else
			return (color);
	}
}

t_color	get_checkerboard_sphere(t_sphere sphere, t_coordinate hit_point, \
		t_screen screen)
{
	t_vector	center_to_hit;
	t_vector	xy_plane;
	t_vector	z_axis;
	double		xy_angle;
	double		z_angle;

	center_to_hit = get_vector_two_point(sphere.center, hit_point);
	xy_plane = screen.vertical;
	z_axis = screen.horizontal;
	xy_angle = radian_to_degree((vector_dot(xy_plane, center_to_hit) \
				/ vector_length(center_to_hit))) + 360;
	z_angle = radian_to_degree((vector_dot(z_axis, center_to_hit) \
				/ vector_length(center_to_hit))) + 180;
	if (!sphere.checker)
		return (sphere.color);
	return (which_color(sphere.color, xy_angle, z_angle));
}
