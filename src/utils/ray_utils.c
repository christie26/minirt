/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:50:52 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:50:52 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_coordinate	get_closer_point(t_coordinate hit_point_1, \
		t_coordinate hit_point_2, t_ray ray)
{
	if (get_distance(ray.origin, hit_point_1) < get_distance(ray.origin, \
			hit_point_2))
		return (hit_point_1);
	return (hit_point_2);
}

t_coordinate	get_closer_hit_point(double t_1, double t_2, t_ray ray)
{
	t_coordinate	closer_hit_point;

	closer_hit_point = get_closer_point(calculate_hit_point(ray, t_1), \
			calculate_hit_point(ray, t_2), ray);
	return (closer_hit_point);
}

void	print_vector(t_vector vector)
{
	printf("(%.f,%.f,%.f)\n", vector.x, vector.y, vector.z);
}

void	print_coordinate(t_coordinate coordinate)
{
	printf("(%.f,%.f,%.f)\n", coordinate.x, coordinate.y, coordinate.z);
}
