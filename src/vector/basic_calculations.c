#include "../../includes/minirt.h"

t_vector	vector_add(t_vector *v1, t_vector *v2)
{
	t_vector	result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}

t_vector	vector_sub(t_vector *v1, t_vector *v2)
{
	t_vector	result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

t_vector	vector_mult(t_vector *v1, t_vector *v2)
{
	t_vector	result;

	result.x = v1->x * v2->x;
	result.y = v1->y * v2->y;
	result.z = v1->z * v2->z;
	return (result);
}

t_vector	vector_mult_scalar(t_vector *v1, double t)
{
	t_vector	result;

	result.x = v1->x * t;
	result.y = v1->y * t;
	result.z = v1->z * t;
	return (result);
}
