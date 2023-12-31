/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:51:02 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:51:03 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	rgb_to_hex(int r, int g, int b)
{
	int	color;

	color = (r << 16) | (g << 8) | b;
	return (color);
}

int	color_to_hex(t_color color)
{
	int	color_hex;

	color_hex = (color.red << 16) | (color.green << 8) | color.blue;
	return (color_hex);
}

t_color	get_obj_color(void *object, int type, t_coordinate hit_point,
		t_screen screen)
{
	if (type == SPHERE)
		return (get_checkerboard_sphere(*(t_sphere *)object, hit_point, \
				screen));
	else if (type == PLANE)
		return (get_checkerboard_plane(*(t_plane *)object, hit_point));
	else if (type == CYLINDER)
		return (get_checkerboard_cylinder(*(t_cylinder *)object, hit_point));
	else
		return (((t_paraboloid *)object)->color);
}

t_color	adjust_color(t_color color, double scala)
{
	t_color	new_color;

	new_color.red = color.red * scala;
	new_color.green = color.green * scala;
	new_color.blue = color.blue * scala;
	return (new_color);
}
