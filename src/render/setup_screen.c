/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:50:20 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:50:21 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static double	degree_to_radian(double fov)
{
	fov = fov * PI / 180;
	return (fov);
}

void	setup_screen(t_data *data)
{
	t_vector	world_vertical;
	t_screen	screen;

	screen = data->screen;
	screen.distance = 1;
	screen.view_width = 2 * fabs(tan(degree_to_radian(data->camera.fov / 2)));
	screen.view_height = screen.view_width * (WINDOW_HEIGHT
			/ (double)WINDOW_WIDTH);
	world_vertical = get_world_vertical(data->camera.vector);
	screen.horizontal = vector_unit(vector_cross(world_vertical, \
				data->camera.vector));
	screen.horizontal = vector_mult_scalar(screen.horizontal, \
			screen.view_width);
	screen.vertical = vector_unit(vector_cross(data->camera.vector, \
				screen.horizontal));
	screen.vertical = vector_mult_scalar(screen.vertical, screen.view_height);
	screen.start_point = get_start_corner(data->camera, screen.horizontal, \
			screen.vertical, screen.distance);
	data->screen = screen;
}
