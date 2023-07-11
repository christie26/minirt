/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_center.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:50:19 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:50:20 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	find_blocked_object(void *object, t_ray hit_to_light, int type)
{
	if (type == SPHERE)
	{
		if (blocked_sphere(*(t_sphere *)object, hit_to_light))
			return (1);
	}
	else if (type == PLANE)
	{
		if (blocked_plane(*(t_plane *)object, hit_to_light))
			return (1);
	}
	else if (type == CYLINDER)
	{
		if (blocked_cylinder(*(t_cylinder *)object, hit_to_light))
			return (1);
	}
	else if (blocked_paraboloid(*(t_paraboloid *)object, hit_to_light))
		return (1);
	return (0);
}

int	is_shadow(t_data data, t_ray hit_to_light)
{
	t_node	*node;
	void	*object;

	node = data.object_list->headnode;
	while (node)
	{
		object = node->object;
		if (find_blocked_object(object, hit_to_light, node->type))
			return (1);
		node = node->next;
	}
	return (0);
}

double	get_light_ratio(t_data data, t_coordinate hit_point, t_ray *ray, \
		t_light light)
{
	t_ray	hit_to_light;
	double	light_ratio;

	hit_to_light = get_hit_to_light(hit_point, light);
	if (is_shadow(data, hit_to_light))
		return (0);
	ray->hit_direction = hit_to_light.direction;
	light_ratio = vector_dot(ray->hit_normal, hit_to_light.direction);
	return (light_ratio);
}
