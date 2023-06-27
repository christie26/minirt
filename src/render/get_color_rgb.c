#include "../../includes/minirt.h"

// static t_color	ray_sky_color(t_ray ray)
// {
// 	double		ratio;
// 	t_color		color_rgb;
// 	t_vector	unit_vector;

// 	unit_vector = vector_unit(ray.direction);
// 	ratio = 0.5 * (unit_vector.y + 1);
// 	color_rgb = mix_color(get_color("255,255,255"), \
// 			get_color("30,144,255"), ratio);
// 	return (color_rgb);
// }

static	t_color	apply_brightness(t_color color, double brightness)
{
	color.red *= brightness;
	color.green *= brightness;
	color.blue *= brightness;
	return (color);
}

t_color	add_color(t_color color_one, t_color color_two)
{
	t_color	color_rgb;

	color_rgb.red = get_smaller_value(color_one.red + color_two.red, 255);
	color_rgb.green = get_smaller_value(color_one.green + color_two.green, 255);
	color_rgb.blue = get_smaller_value(color_one.blue + color_two.blue, 255);
	return (color_rgb);
}

t_color	multiply_color(t_color color_one, t_color color_two)
{
	t_color	color_rgb;

	color_rgb.red = get_smaller_value(color_one.red * color_two.red, 255);
	color_rgb.green = get_smaller_value(color_one.green * color_two.green, 255);
	color_rgb.blue = get_smaller_value(color_one.blue * color_two.blue, 255);
	return (color_rgb);
}

static t_color	get_sphere_color(t_sphere sphere, t_light light, t_ambient ambient, t_coordinate hit_point)
{
	t_color		color_rgb;
	t_vector	light_vector;
	double		light_ratio;

	light_vector = vector_unit(get_vector_two_point(light.coordinate, hit_point));
	light_ratio = vector_dot(light_vector, sphere.normal);
	if (light_ratio < 0)
		return (ambient.color);
	color_rgb = add_color(multiply_color(sphere.color, ambient.color), \
		mix_color(sphere.color, light.color, light_ratio));
	return (color_rgb);
}

t_color	get_color_rgb(t_ray ray, t_data *data)
{
	t_coordinate hit_point;

	data->ambient.color = apply_brightness(data->ambient.color, data->ambient.ratio);
	data->light.color = apply_brightness(data->light.color, data->light.brightness);
	if (hit_sphere(data->sphere, ray))
	{
		hit_point = get_sphere_point(data->sphere, ray);
		data->sphere.normal = vector_unit(get_vector_two_point(data->sphere.center, hit_point));
		return (get_sphere_color(data->sphere, data->light, data->ambient, hit_point));
	}
	else
		return (data->ambient.color);
}