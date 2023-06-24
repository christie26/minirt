/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:51:32 by minkim3           #+#    #+#             */
/*   Updated: 2023/06/24 21:55:01 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_plane	get_plane(char **tab)
{
	t_plane	plane;

	plane.cordinate = get_coordinate(tab[1]);
	plane.vector = get_vector(tab[2]);
	plane.color = get_color(tab[3]);
	return (plane);
}
