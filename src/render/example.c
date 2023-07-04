#include <stdio.h>
#include <math.h>

int isPointOnParaboloid(double x, double y, double z, double h, double k, double l, double vx, double vy, double vz, double px, double py) {
    double transformedX = (x - h) * vx + (y - k) * vy;
    double transformedY = (x - h) * -vy + (y - k) * vx;
    double transformedZ = (x - h) * vx + (y - k) * vy - l;
    
    double paraboloidEquation = pow(transformedX, 2) / px + pow(transformedY, 2) / py - transformedZ;
    
    return (fabs(paraboloidEquation) < 0.0001); // Adjust the tolerance as needed
}

int main() {
    double h, k, l, vx, vy, vz, px, py;
    double x, y, z;
    

	x = ray.origin.x + ray.direction.x * t;
	y = ray.origin.y + ray.direction.y * t;
	z = ray.origin.z + ray.direction.z * t;
    printf("Enter the center point (h, k, l): ");
    scanf("%lf %lf %lf", &h, &k, &l);
    
    printf("Enter the rotation vector (vx, vy, vz): ");
    scanf("%lf %lf %lf", &vx, &vy, &vz);
    
    printf("Enter the parameter px: ");
    scanf("%lf", &px);
    
    printf("Enter the parameter py: ");
    scanf("%lf", &py);
    
    printf("Enter the point coordinates (x, y, z): ");
    scanf("%lf %lf %lf", &x, &y, &z);
    
    if (isPointOnParaboloid(x, y, z, h, k, l, vx, vy, vz, px, py)) {
        printf("The point (%.2f, %.2f, %.2f) is on the paraboloid.\n", x, y, z);
    } else {
        printf("The point (%.2f, %.2f, %.2f) is not on the paraboloid.\n", x, y, z);
    }
    
    return 0;
}

#include <stdio.h>
#include <math.h>

void transformPoints(double *x, double *y, double *z, double vx, double vy, double vz) {
    // Calculate the rotation angles
    double theta = atan2(vy, vx);
    double phi = atan2(sqrt(vx * vx + vy * vy), vz);

    // Perform the coordinate transformation
    double newX = (*x) * cos(theta) * sin(phi) + (*y) * sin(theta) * sin(phi) + (*z) * cos(phi);
    double newY = -(*x) * sin(theta) + (*y) * cos(theta);
    double newZ = (*x) * cos(theta) * cos(phi) + (*y) * sin(theta) * cos(phi) - (*z) * sin(phi);

    // Update the original point with the transformed coordinates
    *x = newX;
    *y = newY;
    *z = newZ;
}

int main() {
    double x, y, z;
    double vx, vy, vz;

    printf("Enter the point coordinates (x, y, z): ");
    scanf("%lf %lf %lf", &x, &y, &z);

    printf("Enter the vector components (vx, vy, vz): ");
    scanf("%lf %lf %lf", &vx, &vy, &vz);

    // Transform the points
    transformPoints(&x, &y, &z, vx, vy, vz);

    printf("The transformed point coordinates are (%.2f, %.2f, %.2f)\n", x, y, z);

    return 0;
}



t_hit_paraboloid hit_paraboloid(t_paraboloid paraboloid, t_ray *ray)
{
    t_hit_paraboloid hit;
    
    t_vector oc = get_vector_two_point(paraboloid.coordinate, ray->origin);
    double k = vector_dot(ray->direction, paraboloid.vector);
    
    double a = vector_dot(ray->direction, ray->direction) - pow(k, 2);
    double b = 2.0 * (vector_dot(ray->direction, oc) - k * vector_dot(oc, paraboloid.vector));
    double c = vector_dot(oc, oc) - pow(vector_dot(oc, paraboloid.vector), 2) - paraboloid.parameter_x * pow(paraboloid.parameter_y, 2);
    
    double discriminant = pow(b, 2) - 4 * a * c;
    
    if (discriminant < 0)
    {
        hit.intersect = 0;
        return hit;
    }
    
    double t_1 = (-b - sqrt(discriminant)) / (2 * a);
    double t_2 = (-b + sqrt(discriminant)) / (2 * a);
    
    if (t_1 > t_2)
        ft_swap_double(&t_1, &t_2);
    
    hit.intersect = 1;
    hit.t = t_1;
    hit.point = get_point_from_ray(*ray, t_1);
    hit.normal = get_paraboloid_normal(paraboloid, hit.point);
    hit.color = paraboloid.color;
    
    return hit;
}


t_hit_paraboloid	hit_paraboloid(t_paraboloid paraboloid, t_ray *ray)
{
	t_hit_paraboloid	hit;
	double				t;
	double				transformed_x;
	double				transformed_y;
	double				transformed_z;
	double				x;
	double				y;
	double				z;
	t_coordinate		center;
	t_vector			vector;

	// t = 0.1;
	x = ray->origin.x + ray->direction.x * t;
	y = ray->origin.y + ray->direction.y * t;
	z = ray->origin.z + ray->direction.z * t;

	center = paraboloid.coordinate;
	x -= center.x;
	y -= center.y;
	z -= center.z;
	
	vector = paraboloid.vector;

    double theta = atan2(vector.y, vector.x);
    double phi = atan2(sqrt(vector.x * vector.x + vector.y * vector.y), vector.z);

	transformed_x = x * cos(theta) * sin(phi) + y * sin(theta) * sin(phi) + z * cos(phi);
	transformed_y = -x * sin(theta) + y * cos(theta);
	transformed_z = x * cos(theta) * cos(phi) + y * sin(theta) * cos(phi) - z * sin(phi);

	double paraboloidEquation = pow(transformed_x, 2) / pow(paraboloid.parameter_x, 2) + pow(transformed_y, 2) / pow(paraboloid.parameter_y, 2) - transformed_z;
    
    return (fabs(paraboloidEquation) < 0.0001);


	hit.oc = get_vector_two_point(paraboloid.coordinate, ray->origin);
	hit.k = vector_dot(ray->direction, paraboloid.vector);

	hit.a = vector_dot(ray->direction, ray->direction) - pow(hit.k, 2);
	hit.b = 2.0 * (vector_dot(ray->direction, hit.oc) - hit.k * vector_dot(hit.oc, cylinder.vector));
	hit.c = vector_dot(hit.oc, hit.oc) - pow(vector_dot(hit.oc, cylinder.vector), 2) - pow(cylinder.diameter / 2, 2);
	
	hit.a = vector_dot(ray->direction, ray->direction);
	hit.b = 2.0 * vector_dot(ray->direction, hit.oc);
	hit.c = vector_dot(hit.oc, hit.oc) - pow(cylinder.diameter / 2, 2);
	

	hit.discriminant = pow(hit.b, 2) - 4 * hit.a * hit.c;
	hit.t_1 = quadratic_equation_1(hit.a, hit.b, hit.c);
	hit.t_2 = quadratic_equation_2(hit.a, hit.b, hit.c);
	return (hit);
}