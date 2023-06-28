#include "../../includes/minirt.h"

t_color sky_color(t_ray ray)
{
    t_color     color_rgb;
    t_vector    unit_vector;
    double      ratio;

    unit_vector = vector_unit(ray.direction);
    ratio = 0.5 * (unit_vector.y + 1);
    color_rgb = mix_color(get_color("255,255,255"), get_color("30,144,255"), ratio);
    return (color_rgb);
}

static t_color	get_color_rgb(t_ray ray, t_data *data)
{
	t_coordinate	hit_point;
	t_color			background_color;

	background_color = sky_color(ray);
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
	t_ray	ray;
	t_color	color_rgb;
	int		color_hex;
	double	u;
	double	v;

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
