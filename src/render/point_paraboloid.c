#include "../../includes/minirt.h"

double get_hit_base_paraboloid(t_ray *ray, t_paraboloid paraboloid, double t)
{
	t_coordinate	intersection_point;
	t_vector		base_to_intersection;

	intersection_point = calculate_hit_point(*ray, t);
	base_to_intersection = get_vector_two_point(paraboloid.coordinate, intersection_point);
	return vector_dot(base_to_intersection, paraboloid.vector);
}

t_hit_paraboloid	hit_paraboloid(t_paraboloid paraboloid, t_ray *ray)
{
	t_hit_paraboloid	hit;

    t_vector oc = get_vector_two_point(paraboloid.coordinate, ray->origin);

	double A = pow(ray->direction.x, 2) / pow(paraboloid.parameter_x, 2) + 
				pow(ray->direction.y, 2) / pow(paraboloid.parameter_y, 2);
	double B = 2 * ((ray->direction.x * oc.x) / pow(paraboloid.parameter_x, 2) +
				(ray->direction.y * oc.y) / pow(paraboloid.parameter_y, 2)) -
				ray->direction.z;
	double C = pow(oc.x, 2) / pow(paraboloid.parameter_x, 2) + 
				pow(oc.y, 2) / pow(paraboloid.parameter_y, 2) - oc.z;

	double discriminant = B * B - 4 * A * C;

	if (discriminant < 0)
	{
		hit.t_1 = -1;
		hit.t_2 = -1;
	}
	else
	{
		hit.t_1 = (-B - sqrt(discriminant)) / (2 * A);
		hit.t_2 = (-B + sqrt(discriminant)) / (2 * A);
	}

	hit.base = get_hit_base_paraboloid(ray, paraboloid, hit.t_1);
	hit.top = get_hit_base_paraboloid(ray, paraboloid, hit.t_2);
	return hit;
}

int is_hit_point_within_paraboloid(double hit_base, double hit_top, double height)
{
	if ((hit_base >= 0 && hit_base <= height) || (hit_top >= 0 && hit_top <= height))
		return (1);
	return (0);
}

t_coordinate	get_closer_paraboloid_point(t_paraboloid paraboloid, t_ray *ray)
{
	t_coordinate	hit_point;
	t_hit_paraboloid	info;

	hit_point = init_hit_point();
	info = hit_paraboloid(paraboloid, ray);
	if (info.t_1 < 0 && info.t_2 < 0)
		return hit_point;
	hit_point = get_closer_hit_point(info.t_1, info.t_2, *ray);
	if (!is_hit_point_within_paraboloid(info.base, info.top, paraboloid.height))
		return init_hit_point();
	return hit_point;
}
