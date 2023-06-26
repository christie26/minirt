#include "../../includes/minirt.h"

void	get_pixel_color(t_data *data, t_render render)
{
	t_ray ray;
	t_color color_rgb;
	int color_hex;
	double u;
	double v;

	for (int j = render.window_height - 1; j >= 0; --j)
	{
		for (int i = 0; i < render.window_width; ++i)
		{
			u = (double)(i) / (render.window_width - 1);
			v = (double)(j) / (render.window_height - 1);
			ray.origin = render.origin;
			ray.direction = get_ray_direction(render.lower_left_corner,
					render.horizontal, render.vertical, render.origin, u, v);
			color_rgb = get_color_rgb(ray, data);
			color_hex = color_to_hex(color_rgb);
			// if (i == 0)
			// printf("(%d, %d) -> %d, %d, %d\n", i, j, color_rgb.red, color_rgb.green, color_rgb.blue);
			write_pixel_image(data, i, j, color_hex);
		}
	}
	// exit(1);
	// while (1);
}
