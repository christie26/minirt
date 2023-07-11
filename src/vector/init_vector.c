/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:50:47 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:50:47 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	init_vector(double x, double y, double z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vector	cord_to_vec(t_coordinate coordinate)
{
	t_vector	vector;

	vector.x = coordinate.x;
	vector.y = coordinate.y;
	vector.z = coordinate.z;
	return (vector);
}

t_vector	get_vector_two_point(t_coordinate start, t_coordinate end)
{
	t_vector	vector;

	vector.x = end.x - start.x;
	vector.y = end.y - start.y;
	vector.z = end.z - start.z;
	return (vector);
}

t_coordinate	vec_to_cord(t_vector vec)
{
	t_coordinate	coord;

	coord.x = vec.x;
	coord.y = vec.y;
	coord.z = vec.z;
	return (coord);
}
