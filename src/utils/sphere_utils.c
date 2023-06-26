#include "../../includes/minirt.h"
#include "../../includes/utils.h"

bool hit_sphere(t_sphere sphere, t_ray ray)
{
    t_vector dif;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	dif = get_vector_two_point(ray.origin, sphere.center);
	a = vector_dot(ray.direction, ray.direction);
	b = 2 * vector_dot(dif, ray.direction);
	c = vector_dot(ray.direction, ray.direction) - sphere.diameter / 2 * sphere.diameter / 2;
	discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}
