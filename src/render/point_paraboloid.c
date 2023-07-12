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

t_hit_paraboloid	hit_normalized_paraboloid(t_paraboloid parab, t_ray ray)
{
	t_hit_paraboloid	hit;
	const t_vector		oc = cord_to_vec(ray.origin);

	hit.a = pow(ray.direction.x, 2) / pow(parab.parameter_x, 2) + \
				pow(ray.direction.y, 2) / pow(parab.parameter_y, 2);
	hit.b = 2 * ((ray.direction.x * oc.x) / pow(parab.parameter_x, 2) + \
				(ray.direction.y * oc.y) / pow(parab.parameter_y, 2)) - \
				ray.direction.z;
	hit.c = pow(oc.x, 2) / pow(parab.parameter_x, 2) + \
				pow(oc.y, 2) / pow(parab.parameter_y, 2) - oc.z;
	hit.discriminant = hit.b * hit.b - 4 * hit.a * hit.c;
	if (hit.discriminant < 0)
	{
		hit.t_1 = -1;
		hit.t_2 = -1;
	}
	else
	{
		hit.t_1 = (-hit.b - sqrt(hit.discriminant)) / (2 * hit.a);
		hit.t_2 = (-hit.b + sqrt(hit.discriminant)) / (2 * hit.a);
	}
	return (hit);
}

void	get_z_and_normal(double t, t_coordinate *hit_point, \
					t_vector *normal, t_paraboloid paraboloid)
{
	double	z;

	if (t > 0)
	{
		z = pow(hit_point->x, 2) / pow(paraboloid.parameter_x, 2) \
			+ pow(hit_point->y, 2) / pow(paraboloid.parameter_y, 2);
		if (z > paraboloid.height)
			*hit_point = init_hit_point();
		else
		{
			*normal = get_normal_vector(*hit_point, paraboloid);
			*normal = rotate_vector(*normal, paraboloid.rot_angle);
			*hit_point = vec_to_cord(vector_add(rotate_vector(cord_to_vec(\
				*hit_point), paraboloid.rot_angle), \
				cord_to_vec(paraboloid.coordinate)));
		}
	}
}

t_hit_paraboloid	hit_paraboloid(t_paraboloid paraboloid, t_ray *ray)
{
	const t_vector		inverse_translation = vector_mult_scalar(\
						cord_to_vec(paraboloid.coordinate), -1);
	t_vector			inverse_rotation;
	t_ray				transformed_ray;
	t_hit_paraboloid	hit;

	paraboloid.rot_angle = get_rotation_angle(paraboloid);
	inverse_rotation = vector_mult_scalar(paraboloid.rot_angle, -1);
	transformed_ray = get_trans_ray(ray, inverse_translation, inverse_rotation);
	hit = hit_normalized_paraboloid(paraboloid, transformed_ray);
	hit.hit_point_1 = calculate_hit_point(transformed_ray, hit.t_1);
	hit.hit_point_2 = calculate_hit_point(transformed_ray, hit.t_2);
	get_z_and_normal(hit.t_1, &hit.hit_point_1, &hit.normal_1, paraboloid);
	get_z_and_normal(hit.t_2, &hit.hit_point_2, &hit.normal_2, paraboloid);
	return (hit);
}

t_coordinate	get_closer_paraboloid_point(t_paraboloid paraboloid, t_ray *ray)
{
	t_coordinate		hit_point;
	t_hit_paraboloid	info;
	double				distance_1;
	double				distance_2;

	hit_point = init_hit_point();
	info = hit_paraboloid(paraboloid, ray);
	if ((info.t_1 < 0 && info.t_2 < 0) || \
		(info.hit_point_1.x == INFINITY && info.hit_point_2.x == INFINITY))
		return (hit_point);
	distance_1 = get_distance(ray->origin, calculate_hit_point(*ray, info.t_1));
	distance_2 = get_distance(ray->origin, calculate_hit_point(*ray, info.t_2));
	if (info.hit_point_1.x == INFINITY)
		distance_1 = INFINITY;
	if (info.hit_point_2.x == INFINITY)
		distance_2 = INFINITY;
	if (distance_1 < distance_2)
	{
		hit_point = info.hit_point_1;
		ray->hit_normal = info.normal_1;
		return (hit_point);
	}
	hit_point = info.hit_point_2;
	ray->hit_normal = info.normal_2;
	return (hit_point);
}
