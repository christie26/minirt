#include "../../includes/minirt.h"


double	get_short_distance(t_list *object_list, t_ray *ray)
{
	t_node			*node;
	double			short_distance;
	t_coordinate	hit_point;
	void			*object;

	node = object_list->headnode;
	short_distance = INFINITY;
	while (node)
	{
		object = node->object;
		hit_point = get_hit_point(ray, node);
		if (short_distance > get_distance(hit_point, ray->origin))
		{
			ray->object = object;
			ray->object_type = node->type;
			ray->hit_point = hit_point;
			short_distance = get_distance(hit_point, ray->origin);
		}
		node = node->next;
	}
	return (short_distance);
}
