/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_paraboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:50:24 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:50:25 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	get_hit_base_paraboloid(t_ray ray, t_paraboloid paraboloid, double t)
{
	t_coordinate	intersection_point;
	t_vector		base_to_intersection;

	intersection_point = calculate_hit_point(ray, t);
	base_to_intersection = get_vector_two_point(paraboloid.coordinate, \
													intersection_point);
	return (vector_dot(base_to_intersection, paraboloid.vector));
}

t_vector	get_normal_vector(t_coordinate hit_point, t_paraboloid paraboloid)
{
	t_vector	normal;

	normal.x = pow(paraboloid.parameter_y, 2) * hit_point.x;
	normal.y = pow(paraboloid.parameter_x, 2) * hit_point.y;
	normal.z = - (pow(paraboloid.parameter_x, 2) * \
				pow(paraboloid.parameter_y, 2) / 2);
	normal = vector_unit(normal);
	return (normal);
}

t_vector	get_rotation_angle(t_paraboloid paraboloid)
{
	t_vector	rotation_angle;

	if (paraboloid.vector.y == 0)
		rotation_angle.x = 0;
	else
		rotation_angle.x = - (acos(paraboloid.vector.z / \
			sqrt(pow(paraboloid.vector.y, 2)) - pow(paraboloid.vector.z, 2)));
	if (paraboloid.vector.x == 0)
		rotation_angle.y = 0;
	else
		rotation_angle.y = - (acos(paraboloid.vector.z / \
			sqrt(pow(paraboloid.vector.x, 2)) - pow(paraboloid.vector.z, 2)));
	return (rotation_angle);
}

t_ray	get_trans_ray(t_ray *ray, t_vector inverse_trans, t_vector inverse_ro)
{
	t_ray	transformed_ray;

	transformed_ray.origin = vec_to_cord(rotate_vector(vector_add \
	(cord_to_vec(ray->origin), inverse_trans), inverse_ro));
	transformed_ray.direction = rotate_vector(ray->direction, inverse_ro);
	return (transformed_ray);
}

int is_hit_point_within_paraboloid(double hit_base, double hit_top, double height)
{
	if ((hit_base >= 0 && hit_base <= height) || (hit_top >= 0 && hit_top <= height))
		return (1);
	return (0);
}
