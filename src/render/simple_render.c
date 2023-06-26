#include "../../includes/minirt.h"

// 여기에서 쓰는 계산식은 특수한 경우이다. 
// 일반적인 경우에 적용 가능한 함수를 만들어야 한다. 
t_coordinate  get_start_corner(t_coordinate origin, t_vector horizontal, \
                            t_vector vertical, double focal_length)
{
    t_coordinate    start_corner;

    start_corner.x = origin.x - horizontal.x / 2 - vertical.x / 2;
    start_corner.y = origin.y - horizontal.y / 2 - vertical.y / 2;
    start_corner.z = origin.z - horizontal.z / 2 - vertical.z / 2 - focal_length;
    return (start_corner);
}  

t_vector get_ray_direction(t_coordinate lower_left_corner, t_vector horizontal, \
                            t_vector vertical, t_coordinate origin, double u, double v)
{
    t_vector        ray_direction;
    t_coordinate    pixel;

    pixel.x = lower_left_corner.x + u * horizontal.x + v * vertical.x - origin.x;
    pixel.y = lower_left_corner.y + u * horizontal.y + v * vertical.y - origin.y;
    pixel.z = lower_left_corner.z + u * horizontal.z + v * vertical.z - origin.z;
    
    ray_direction = get_vector_two_point(origin, pixel);
    return (ray_direction);
}

t_color ray_color_sky(t_ray ray, t_data *data)
{
    t_color     color_rgb;
    t_vector    unit_vector;
    double      ratio;

    // if (data->sphere)
        if (hit_sphere(data->sphere, ray))
            return (data->sphere.color);
    unit_vector = get_unit_vector(ray.direction);
    ratio = 0.5 * (unit_vector.y + 1);
    color_rgb = gredient_color(get_color("255,255,255"), get_color("30,144,255"), ratio);
    return (color_rgb);
}

void	write_pixel_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	// if (x > 950 || x < 50 || y > 950 | y < 50)
		// return ;
    // printf("data->addr = %p, color = %d\n", data->addr, color);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    // printf("dst = %p\n", dst);
	*(unsigned int *)dst = color;
	return ;
}

void	simple_render(t_data *data)
{

	setup_screen(data, 1920, 1080);
    const int image_width = data->screen.resolution_width;
    const int image_height = data->screen.resolution_height;
    double viewport_height = data->screen.height;
    double viewport_width = data->screen.width;
    double focal_length = 1.0; // like ede-thom's project !! 

	t_coordinate origin = get_coordinate_double(0, 0, 0); // coordinate of camera
    t_vector horizontal = init_vector(viewport_width, 0, 0);
    t_vector vertical = init_vector(0, viewport_height, 0);

    // set lower_left_corner coordinate
    t_coordinate lower_left_corner \
        = get_start_corner(origin, horizontal, vertical, focal_length);


    // Render
    t_ray   ray;
    t_color color_rgb;
    int     color_hex;

    // printf("image width: %d, image height: %d\n", image_width, image_height);
    for (int j = image_height-1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            double u = (double)(i) / (image_width-1);
            double v = (double)(j) / (image_height-1);
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
