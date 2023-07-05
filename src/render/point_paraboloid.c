
#include "../../includes/minirt.h"

double get_hit_base_paraboloid(t_ray *ray, t_paraboloid paraboloid, double t)
{
    t_coordinate intersection_point;
    t_vector base_to_intersection;

    intersection_point = calculate_hit_point(*ray, t);
    base_to_intersection = get_vector_two_point(paraboloid.coordinate, intersection_point);
    return vector_dot(base_to_intersection, paraboloid.vector);
}

t_vector rotate_vector(t_vector vec, t_vector rotation_angle)
{
	double cos_x = cos(rotation_angle.x);
	double sin_x = sin(rotation_angle.x);
	double cos_y = cos(rotation_angle.y);
	double sin_y = sin(rotation_angle.y);

    t_vector result;
	// rotate x-axis, angle_x
    result.y = cos_x*vec.y - sin_x*vec.z;
    result.z = sin_x*vec.y + cos_x*vec.z;

    vec.y = result.y;
    vec.z = result.z;

	// rotate y-axis, angle_y
    result.x = cos_y*vec.x + sin_y*vec.z;
    result.z = -sin_y*vec.x + cos_y*vec.z;

    return result;
}

t_coordinate vector_to_coordinate(t_vector vec) 
{
    t_coordinate coord;
    coord.x = vec.x;
    coord.y = vec.y;
    coord.z = vec.z;
    return coord;
}

t_hit_paraboloid	hit_normalized_paraboloid(t_paraboloid paraboloid, t_ray *ray)
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

t_hit_paraboloid hit_paraboloid(t_paraboloid paraboloid, t_ray *ray)
{
    // Define the inverse transformation: translate by the negation of the object's translation and then rotate by the negation of the object's rotation.
	t_vector rotation_angle;

	if (paraboloid.vector.y == 0)
		rotation_angle.x = 0;
	else                                   
		rotation_angle.x = acos(paraboloid.vector.z / sqrt(pow(paraboloid.vector.y, 2) + pow(paraboloid.vector.z, 2))); 
	if (paraboloid.vector.x == 0)
		rotation_angle.y = 0;
	else
		rotation_angle.y = acos(paraboloid.vector.z / sqrt(pow(paraboloid.vector.x, 2) + pow(paraboloid.vector.z, 2))); 

    t_vector inverse_translation = vector_mult_scalar(coordinate_to_vector(paraboloid.coordinate), -1);
    t_vector inverse_rotation = vector_mult_scalar(rotation_angle, -1);

    // Transform the ray
    t_ray transformed_ray;
    transformed_ray.origin = vector_to_coordinate(rotate_vector(vector_sub(coordinate_to_vector(ray->origin), inverse_translation), inverse_rotation));
    transformed_ray.direction = rotate_vector(ray->direction, inverse_rotation);

	// printf("(%.2f,%.2f,%.2f)->(%.2f,%.2f,%.2f)\n",ray->direction.x,ray->direction.y,ray->direction.z,
	// 					transformed_ray.direction.x,transformed_ray.direction.y,transformed_ray.direction.z);

    // Perform intersection test
    t_hit_paraboloid hit = hit_normalized_paraboloid(paraboloid, &transformed_ray);

    // Calculate hit points and transform them back to world coordinates
    hit.hit_point_1 = calculate_hit_point(transformed_ray, hit.t_1);
    hit.hit_point_2 = calculate_hit_point(transformed_ray, hit.t_2);

    // Rotate back first, then translate
    hit.hit_point_1 = vector_to_coordinate(vector_sub(rotate_vector(coordinate_to_vector(hit.hit_point_1), rotation_angle), coordinate_to_vector(paraboloid.coordinate)));
    hit.hit_point_2 = vector_to_coordinate(vector_sub(rotate_vector(coordinate_to_vector(hit.hit_point_2), rotation_angle), coordinate_to_vector(paraboloid.coordinate)));
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
	// info = hit_normalized_paraboloid(paraboloid, ray);
	if (info.t_1 < 0 && info.t_2 < 0)
		return hit_point;
	hit_point = get_closer_hit_point(info.t_1, info.t_2, *ray);
	// if (!is_hit_point_within_paraboloid(info.base, info.top, paraboloid.height))
	// 	return init_hit_point();
	return hit_point;
}