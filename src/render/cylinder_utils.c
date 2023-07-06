#include "../../includes/minirt.h"

int is_lid(t_cylinder cylinder, t_coordinate hit_point)
{
	t_vector hit_to_base;
	t_vector hit_to_top;

	hit_to_base = get_vector_two_point(hit_point, cylinder.base);
	hit_to_top = get_vector_two_point(hit_point, cylinder.top);

	if (vector_dot(cylinder.vector, hit_to_base) < 0.01)
		return (BASE);
	else if (vector_dot(cylinder.vector, hit_to_top) < 0.01)
		return (TOP);
	else
		return (NOT_LID);
}