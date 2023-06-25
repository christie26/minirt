/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:50:16 by minkim3           #+#    #+#             */
/*   Updated: 2023/06/24 21:50:21 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_camera	get_camera(char **tab)
{
	t_camera	camera;

	camera.cordinate = get_coordinate(tab[1]);
	camera.vector = get_vector(tab[2]);
	camera.fov = get_double(tab[3]);
	return (camera);
}
