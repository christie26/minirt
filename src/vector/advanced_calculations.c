#include "../../includes/minirt.h"

double	vector_length(t_vector *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

double	vector_dot(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vector	vector_cross(t_vector *v1, t_vector *v2)
{
	t_vector	result;

	result.x = v1->y * v2->z - v1->z * v2->y;
	result.y = v1->z * v2->x - v1->x * v2->z;
	result.z = v1->x * v2->y - v1->y * v2->x;
	return (result);
}

t_vector	vector_unit(t_vector *v)
{
	double		len;
	t_vector	result;

	len = vector_length(v);
	if (len == 0)
		return (*v);
	result = vector_mult_scalar(v, 1.0 / len);
	return (result);
}
