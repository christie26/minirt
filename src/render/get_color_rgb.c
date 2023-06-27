#include "../../includes/minirt.h"

static t_color	ray_sky_color(t_ray ray)
{
	double		ratio;
	t_color		color_rgb;
	t_vector	unit_vector;

	unit_vector = vector_unit(ray.direction);
	ratio = 0.5 * (unit_vector.y + 1);
	color_rgb = gredient_color(get_color("255,255,255"), \
			get_color("30,144,255"), ratio);
	return (color_rgb);
}

static	t_color	apply_brightness(t_color color, double brightness)
{
	color.red *= brightness;
	color.green *= brightness;
	color.blue *= brightness;
	return (color);
}

static t_color	get_sphere_color(t_sphere sphere, t_light light, t_ambient ambient, t_coordinate hit_point)
{
	t_color		color_rgb;
	t_color		ambient_color;
	t_vector	light_vector;
	double		light_ratio;

	light_vector = vector_unit(get_vector_two_point(light.coordinate, hit_point));
	light_ratio = vector_dot(light_vector, sphere.normal);
	ambient_color = apply_brightness(ambient.color, ambient.ratio);
	if (light_ratio < 0)
		return (ambient_color);
	light.color = apply_brightness(light.color, light.brightness);
	color_rgb = gredient_color(sphere.color, ambient_color, ambient.ratio);
	color_rgb = gredient_color(sphere.color, light.color, light_ratio);
	return (color_rgb);
}


t_color	get_color_rgb(t_ray ray, t_data *data)
{
	t_color color_rgb;
	t_coordinate hit_point;

	if (hit_sphere(data->sphere, ray))
	{
		hit_point = get_sphere_point(data->sphere, ray);
		data->sphere.normal = vector_unit(get_vector_two_point(data->sphere.center, hit_point));
		color_rgb = get_sphere_color(data->sphere, data->light, data->ambient, hit_point);
		return (color_rgb);
	}
	else
		return (ray_sky_color(ray));
}