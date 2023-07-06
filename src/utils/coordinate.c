#include "../../includes/minirt.h"

t_coordinate add_coordinates(t_coordinate v1, t_coordinate v2)
{
	t_coordinate result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;

	return result;
}

t_coordinate add_coordinates_scalar(t_coordinate v1, double scalar)
{
	t_coordinate result;

	result.x = v1.x + scalar;
	result.y = v1.y + scalar;
	result.z = v1.z + scalar;

	return result;
}

t_coordinate sub_coordinates(t_coordinate v1, t_coordinate v2)
{
	t_coordinate result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;

	return result;
}

t_coordinate coordinate_mult_scalar(t_coordinate vector, double scalar)
{
	t_coordinate result;

	result.x = scalar * vector.x;
	result.y = scalar * vector.y;
	result.z = scalar * vector.z;

	return result;
}

int is_same_coordinate(t_coordinate v1, t_coordinate v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}