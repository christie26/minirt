#include "../../includes/minirt.h"

t_color	ray_color_sky(t_ray ray, t_data *data)
{
	t_color		color_rgb;
	t_vector	unit_vector;
	double		ratio;

	// if (data->sphere)
	if (hit_sphere(data->sphere, ray))
		return (data->sphere.color);
	unit_vector = vector_unit(ray.direction);
	ratio = 0.5 * (unit_vector.y + 1);
	color_rgb = gredient_color(get_color("255,255,255"), \
			get_color("30,144,255"), ratio);
	return (color_rgb);
}

void	get_pixel_color(t_data *data, t_render render)
{
	t_ray ray;
	t_color color_rgb;
	int color_hex;

	for (int j = render.window_height - 1; j >= 0; --j)
	{
		for (int i = 0; i < render.window_width; ++i)
		{
			double u = (double)(i) / (render.window_width - 1);
			double v = (double)(j) / (render.window_height - 1);
			ray.origin = render.origin;
			ray.direction = get_ray_direction(render.lower_left_corner,
					render.horizontal, render.vertical, render.origin, u, v);
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