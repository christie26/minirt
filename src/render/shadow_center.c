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
