
#include "../../includes/minirt.h"

t_vector	init_vector(double x, double y, double z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
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

t_vector    get_unit_vector(t_vector origin_vector)
{
    t_vector    unit_vector;

    unit_vector = vector_mult_scalar(origin_vector, 1 / vector_length(origin_vector));
    return (unit_vector);
}