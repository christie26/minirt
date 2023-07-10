#include "../../includes/minirt.h"

t_vector	get_cylinder_normal(t_cylinder cylinder, t_coordinate hit_point)
{
	t_vector	normal;
	t_vector	v;
	t_vector	p;

	if (fabs(vector_dot(get_vector_two_point(hit_point, cylinder.base),
			cylinder.vector)) < EPSILON)
		normal = vector_mult_scalar(cylinder.vector, -1);
	else if (fabs(vector_dot(get_vector_two_point(hit_point, cylinder.top), \
				cylinder.vector)) < EPSILON)
		normal = cylinder.vector;
	else
	{
		v = get_vector_two_point(cylinder.base, hit_point);
		p = vector_add(coordinate_to_vector(cylinder.base),
				vector_mult_scalar(cylinder.vector, vector_dot(v, \
						cylinder.vector)));
		normal = vector_unit(vector_sub(init_vector(hit_point.x, hit_point.y, \
						hit_point.z), p));
	}
	return (normal);
}
