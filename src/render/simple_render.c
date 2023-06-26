#include "../../includes/minirt.h"

bool hit_sphere(t_coordinate center, double radius, t_ray ray)
{
    t_vector dif;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	dif = get_vector_two_point(ray.origin, center);
	a = vector_dot(ray.direction, ray.direction);
	b = 2 * vector_dot(dif, ray.direction);
	c = vector_dot(ray.direction, ray.direction) - radius * radius;
	discriminant = b * b - 4 * a * c;
	return (discriminant);
}


void	simple_render(t_data *data)
{
	(void)(data);
	// const double aspect_ratio = 16.0 / 9.0;
    // const int image_width = 400;
    // const int image_height = (int)(image_width / aspect_ratio);

    // // Camera

    // double viewport_height = 2.0;
    // double viewport_width = aspect_ratio * viewport_height;
    // double focal_length = 1.0;

	// t_coordinate origin = get_coordinate_double(0, 0, 0);

    // double horizontal = vec3(viewport_width, 0, 0);
    // double vertical = vec3(0, viewport_height, 0);
    // double lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    // // Render

    // std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    // for (int j = image_height-1; j >= 0; --j) {
    //     std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    //     for (int i = 0; i < image_width; ++i) {
    //         auto u = double(i) / (image_width-1);
    //         auto v = double(j) / (image_height-1);
    //         ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
    //         color pixel_color = ray_color(r);
    //         write_color(std::cout, pixel_color);
    //     }
    // }

}
