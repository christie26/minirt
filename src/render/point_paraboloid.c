#include "../../includes/minirt.h"

double	get_hit_base_paraboloid(t_ray *ray, t_paraboloid paraboloid, double t)
{
	t_coordinate	intersection_point;
	t_vector		base_to_intersection;

	intersection_point = calculate_hit_point(*ray, t);
	base_to_intersection = get_vector_two_point(paraboloid.coordinate, \
													intersection_point);
	return (vector_dot(base_to_intersection, paraboloid.vector));
}

t_vector	get_normal_vector(t_coordinate hit_point, t_paraboloid paraboloid)
{
	t_vector	normal;

	normal.x = pow(paraboloid.parameter_y, 2) * hit_point.x;
	normal.y = pow(paraboloid.parameter_x, 2) * hit_point.y;
	normal.z = - pow(paraboloid.parameter_x, 2) * pow(paraboloid.parameter_y, 2) / 2;
	normal = vector_unit(normal);
	return (normal);
}

t_hit_paraboloid	hit_normalized_paraboloid(t_paraboloid paraboloid, t_ray *ray)
{
	t_hit_paraboloid	hit;
	const t_vector		oc = coordinate_to_vector(ray->origin);

	hit.a = pow(ray->direction.x, 2) / pow(paraboloid.parameter_x, 2) + 
				pow(ray->direction.y, 2) / pow(paraboloid.parameter_y, 2);
	hit.b = 2 * ((ray->direction.x * oc.x) / pow(paraboloid.parameter_x, 2) +
				(ray->direction.y * oc.y) / pow(paraboloid.parameter_y, 2)) -
				ray->direction.z;
	hit.c = pow(oc.x, 2) / pow(paraboloid.parameter_x, 2) + 
				pow(oc.y, 2) / pow(paraboloid.parameter_y, 2) - oc.z;
	hit.discriminant = hit.b * hit.b - 4 * hit.a * hit.c;
	if (hit.discriminant < 0)
	{
		hit.t_1 = -1;
		hit.t_2 = -1;
	}
	else
	{
		hit.t_1 = (-hit.b - sqrt(hit.discriminant)) / (2 * hit.a);
		hit.t_2 = (-hit.b + sqrt(hit.discriminant)) / (2 * hit.a);
	}
	hit.base = get_hit_base_paraboloid(ray, paraboloid, hit.t_1);
	hit.top = get_hit_base_paraboloid(ray, paraboloid, hit.t_2);
	return hit;
}

static t_vector	get_rotation_angle(t_paraboloid paraboloid)
{
	t_vector	rotation_angle;

	if (paraboloid.vector.y == 0)
		rotation_angle.x = 0;
	else	   
		rotation_angle.x = -acos(paraboloid.vector.z / sqrt(pow(paraboloid.vector.y, 2) + pow(paraboloid.vector.z, 2))); 
	if (paraboloid.vector.x == 0)
		rotation_angle.y = 0;
	else
		rotation_angle.y = -acos(paraboloid.vector.z / sqrt(pow(paraboloid.vector.x, 2) + pow(paraboloid.vector.z, 2))); 
	return (rotation_angle);
}

t_hit_paraboloid hit_paraboloid(t_paraboloid paraboloid, t_ray *ray)
{
	const t_vector		inverse_translation = vector_mult_scalar(coordinate_to_vector(paraboloid.coordinate), -1);
	t_vector			inverse_rotation;
	t_ray				transformed_ray;
	t_hit_paraboloid	hit;
	// t_vector			normal;

	paraboloid.rotation_angle = get_rotation_angle(paraboloid);
	inverse_rotation = vector_mult_scalar(paraboloid.rotation_angle, -1);
	transformed_ray.origin = vector_to_coordinate(rotate_vector(vector_add(coordinate_to_vector(ray->origin), inverse_translation), inverse_rotation));
	transformed_ray.direction = rotate_vector(ray->direction, inverse_rotation);
	hit = hit_normalized_paraboloid(paraboloid, &transformed_ray);
	hit.hit_point_1 = calculate_hit_point(transformed_ray, hit.t_1);
	hit.hit_point_2 = calculate_hit_point(transformed_ray, hit.t_2);
	hit.normal_1 = get_normal_vector(hit.hit_point_1, paraboloid);
	hit.normal_2 = get_normal_vector(hit.hit_point_2, paraboloid);
	hit.normal_1 = rotate_vector(hit.normal_1, paraboloid.rotation_angle);
	hit.normal_2 = rotate_vector(hit.normal_2, paraboloid.rotation_angle);

	hit.hit_point_1 = vector_to_coordinate(vector_add(rotate_vector(coordinate_to_vector(hit.hit_point_1), paraboloid.rotation_angle), coordinate_to_vector(paraboloid.coordinate)));
	hit.hit_point_2 = vector_to_coordinate(vector_add(rotate_vector(coordinate_to_vector(hit.hit_point_2), paraboloid.rotation_angle), coordinate_to_vector(paraboloid.coordinate)));
	return (hit);
}

int is_hit_point_within_paraboloid(double hit_base, double hit_top, double height)
{
	if ((hit_base >= 0 && hit_base <= height) || (hit_top >= 0 && hit_top <= height))
		return (1);
	return (0);
}

t_coordinate	get_closer_paraboloid_point(t_paraboloid paraboloid, t_ray *ray)
{
	t_coordinate		hit_point;
	t_hit_paraboloid	info;
	double				distance_1;
	double				distance_2;

	hit_point = init_hit_point();
	info = hit_paraboloid(paraboloid, ray);
	if (info.t_1 < 0 && info.t_2 < 0)
		return hit_point;
	
	distance_1 = get_distance(ray->origin, calculate_hit_point(*ray, info.t_1));
	distance_2 = get_distance(ray->origin, calculate_hit_point(*ray, info.t_2));
	if (distance_1 < distance_2)
	{
		hit_point = info.hit_point_1;
		ray->hit_normal = info.normal_1;
	}
	else
	{
		hit_point = info.hit_point_2;
		ray->hit_normal = info.normal_2;
	}
	return hit_point;
}