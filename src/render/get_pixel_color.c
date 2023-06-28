#include "../../includes/minirt.h"

static t_color sky_color(t_ray ray)
{
    t_color     color_rgb;
    t_vector    unit_vector;
    double      ratio;

    unit_vector = vector_unit(ray.direction);
    ratio = 0.5 * (unit_vector.y + 1);
    color_rgb = mix_color(get_color("255,255,255"), get_color("30,144,255"), ratio);
    return (color_rgb);
}

static int hit_shape(t_data *data, t_ray ray)
{
    if (hit_sphere(data->sphere, ray))
        return (SPHERE);
    else if (hit_plane(data->plane, ray))
        return (PLANE);
	else
		return (NONE);
}

static t_coordinate get_shape_point(t_data *data, t_ray ray, int shape)
{
    t_coordinate hit_point;

    if (shape == SPHERE)
		hit_point = get_sphere_point(data->sphere, ray);
	else if (shape == PLANE)
		hit_point = get_plane_point(data->plane, ray);
}

static t_color	get_color_rgb(t_ray ray, t_data *data)
{
	t_coordinate	hit_point;
	int				shape;
	t_color			background_color;

	background_color = sky_color(ray);
	shape = hit_shape(data, ray);
	if (shape != NONE)
	{
		hit_point = get_shape_point(data, ray, shape);
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
