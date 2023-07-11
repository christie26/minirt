/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:49:32 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:49:32 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_camera	get_camera(char **tab, char *bit_mask)
{
	t_camera	camera;

	if (((*bit_mask & 2) == 2))
		error_msg(PARSE_CAMERA);
	if (!tab[1] || !tab[2] || !tab[3])
		error_msg(LACK_ELEMENT);
	camera.coordinate = get_coordinate(tab[1]);
	camera.vector = vector_unit(get_vector(tab[2]));
	camera.fov = get_double(tab[3]);
	if (camera.fov < 0 || camera.fov > 180)
		error_msg(PARSE_CAMERA);
	if (tab[4])
		error_msg(PARSE_CAMERA);
	*bit_mask |= 2;
	return (camera);
}
