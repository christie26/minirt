/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:49:56 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:49:56 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_color	which_color(t_color color, \
	double vertical_len, double horizontal_len)
{
	if (dmod(vertical_len, 1) > 0 && dmod(vertical_len, 1) < 0.5)
	{
		if (dmod(horizontal_len, 1) > 0 && dmod(horizontal_len, 1) < 0.5)
			return (color);
		else
			return (get_color("0,0,0"));
	}
	else
	{
		if (dmod(horizontal_len, 1) > 0 && dmod(horizontal_len, 1) < 0.5)
			return (get_color("0,0,0"));
		else
			return (color);
	}
}

t_color	get_checkerboard_plane(t_plane plane, t_coordinate hit_point)
{
	t_vector	vertical;
	t_vector	horizontal;
	t_vector	point_to_hit;
	double		vertical_len;
	double		horizontal_len;

	vertical = get_world_vertical(plane.vector);
	horizontal = vector_cross(plane.vector, vertical);
	point_to_hit = get_vector_two_point(plane.coordinate, hit_point);
	vertical_len = vector_dot(point_to_hit, vertical) / vector_length(vertical) \
		+ 1000;
	horizontal_len = vector_dot(point_to_hit, horizontal) \
		/ vector_length(horizontal) + 1000;
	if (!plane.checker)
		return (plane.color);
	return (which_color(plane.color, vertical_len, horizontal_len));
}
