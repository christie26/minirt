#include "../../includes/minirt.h"

static t_color	get_color_rgb(t_ray ray, t_data *data)
{
	t_coordinate hit_point;
	t_color background_color;

	background_color = apply_brightness(data->ambient.color, data->ambient.ratio);
	if (hit_sphere(data->sphere, ray))
	{
		hit_point = get_sphere_point(data->sphere, ray);
		return (apply_phong_model(*data, hit_point));
	}
	else
		return (background_color);
}

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
			ray.direction = get_ray_direction(render.lower_left_corner,\
					render.horizontal, render.vertical, render.origin, u, v);
			color_rgb = get_color_rgb(ray, data);
			color_hex = color_to_hex(color_rgb);
			write_pixel_image(data, i, j, color_hex);
		}
	}
}
