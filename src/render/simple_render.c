#include "../../includes/minirt.h"

t_color ray_color_sky(t_ray ray, t_data *data)
{
    t_color     color_rgb;
    t_vector    unit_vector;
    double      ratio;

    // if (data->sphere)
        if (hit_sphere(data->sphere, ray))
            return (data->sphere.color);
    unit_vector = vector_unit(ray.direction);
    ratio = 0.5 * (unit_vector.y + 1);
    color_rgb = gredient_color(get_color("255,255,255"), get_color("30,144,255"), ratio);
    return (color_rgb);
}

void	simple_render(t_data *data)
{

	setup_screen(data, 1920, 1080);
    const int window_width = data->screen.window_width;
    const int window_height = data->screen.window_height;
    double viewport_height = data->screen.view_height;
    double viewport_width = data->screen.view_width;
    double focal_length = data->screen.distance; // like ede-thom's project !! 

	t_coordinate origin = data->camera.coordinate; // coordinate of camera
    t_vector horizontal = init_vector(viewport_width, 0, 0);
    t_vector vertical = init_vector(0, viewport_height, 0);

    // set lower_left_corner coordinate
    t_coordinate lower_left_corner \
        = get_start_corner(origin, horizontal, vertical, focal_length);

    // Render
    t_ray   ray;
    t_color color_rgb;
    int     color_hex;

    // printf("window width: %d, window height: %d\n", window_width, window_height);
    for (int j = window_height-1; j >= 0; --j) {
        for (int i = 0; i < window_width; ++i) {
            double u = (double)(i) / (window_width-1);
            double v = (double)(j) / (window_height-1);
            ray.origin = origin;
            ray.direction = get_ray_direction(lower_left_corner, horizontal, vertical, origin, u, v);
            // color_hex = 0xFFFFFF;
            color_rgb = ray_color_sky(ray, data);
            color_hex = t_color_to_hex(color_rgb);
            // if (i == 0)
                // printf("(%d, %d) -> %d, %d, %d\n", i, j, color_rgb.red, color_rgb.green, color_rgb.blue);
            write_pixel_image(data, i, j, color_hex);
        }
    }
    // exit(1);
    // while (1);
}
