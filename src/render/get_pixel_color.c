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

void	get_pixel_color(t_data *data)
{
	t_ray		ray;
	t_color		color_rgb;
	t_screen	screen;
	int			color_hex;
	double		u;
	double		v;

	screen = data->screen;
	for (int j = screen.window_height - 1; j >= 0; --j)
	{
		for (int i = 0; i < screen.window_width; ++i)
		{
			u = (double)(i) / (screen.window_width - 1);
			v = (double)(j) / (screen.window_height - 1);
			ray.origin = data->camera.coordinate;
			ray.direction = get_ray_direction(screen.start_point,\
					screen.horizontal, screen.vertical, data->camera.coordinate, u, v);
			color_rgb = get_color_rgb(ray, data);
			color_hex = color_to_hex(color_rgb);
			write_pixel_image(data, i, j, color_hex);
		}
	}
}
