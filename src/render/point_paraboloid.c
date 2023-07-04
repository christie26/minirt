#include "../../includes/minirt.h"


t_hit_paraboloid hit_paraboloid(t_paraboloid paraboloid, t_ray *ray)
{
    t_hit_paraboloid hit;

    
    t_vector oc = get_vector_two_point(paraboloid.coordinate, ray->origin);
    double k = vector_dot(ray->direction, paraboloid.vector);
    
    double a = pow(ray->direction.x, 2) / pow(paraboloid.parameter_x, 2) +
               pow(ray->direction.y, 2) / pow(paraboloid.parameter_y, 2) -
               pow(ray->direction.z, 2) - pow(k, 2);
    
    double b = 2.0 * (oc.x * ray->direction.x / pow(paraboloid.parameter_x, 2) +
                      oc.y * ray->direction.y / pow(paraboloid.parameter_y, 2) -
                      pow(k, 2) * oc.z * ray->direction.z);
    
    double c = pow(oc.x, 2) / pow(paraboloid.parameter_x, 2) +
               pow(oc.y, 2) / pow(paraboloid.parameter_y, 2) -
               oc.z;

    // double a = vector_dot(ray->direction, ray->direction) - pow(k, 2);
    // double b = 2.0 * (vector_dot(ray->direction, oc) - k * vector_dot(oc, paraboloid.vector));
    // double c = vector_dot(oc, oc) - pow(vector_dot(oc, paraboloid.vector), 2) - paraboloid.parameter_x * pow(paraboloid.parameter_y, 2);
    
    hit.discriminant = pow(b, 2) - 4 * a * c;
    hit.t_1 = (-b - sqrt(hit.discriminant)) / (2 * a);
    hit.t_2 = (-b + sqrt(hit.discriminant)) / (2 * a);
    if (hit.t_1 == NAN)
      printf(" a is zero !\n");
    // if (hit.t_1 == nan)
      // printf("a=%.2f\n", a);
    return hit;
}

t_coordinate	get_closer_paraboloid_point(t_paraboloid paraboloid, t_ray *ray)
{
	t_coordinate		hit_point;
	t_hit_paraboloid	info;

	hit_point = init_hit_point();

	info = hit_paraboloid(paraboloid, ray);
	// if (info.discriminant < 0)
	if (info.t_1 < 0 && info.t_2 < 0)
		return (hit_point);
	printf("t_1 = %.1f, t_2 = %.1f\n", info.t_1, info.t_2);
	hit_point = get_closer_hit_point(info.t_1, info.t_2, *ray);
	return (hit_point);
}