#include "../../includes/minirt.h"

// static t_color get_ambient_color(t_color obj_color, t_ambient ambient)
// {
// 	t_color ambient_color;

// 	ambient_color = add_color(obj_color, ambient.color);
// 	ambient_color = apply_brightness(ambient_color, ambient.ratio);
// 	return (ambient_color);
// }

static t_color get_diffuse_color(t_color obj_color, t_light light, double light_ratio)
{
	t_color diffuse_color;
	t_color light_brightness_color;

	light_brightness_color = apply_brightness(light.color, light.brightness);
	light_brightness_color = apply_brightness(light_brightness_color, light_ratio);
	diffuse_color = multiply_color(obj_color, light_brightness_color);
	return (diffuse_color);
}

static double	get_light_ratio(t_data data, t_coordinate hit_point)
{
	t_vector	light_vector;
	double		light_ratio;

	light_vector = vector_unit(get_vector_two_point(hit_point, data.light.coordinate));
	light_ratio = vector_dot(light_vector, data.sphere.normal);
	return (light_ratio);
}

// static t_color add_all_phong_colors(t_phong phong)
// {
// 	t_color phong_color;

// 	phong_color = add_color(phong.ambient_color, phong.diffuse_color);
// 	return (phong_color);
// }

t_color	apply_phong_model(t_data data, t_coordinate hit_point)
{
	// t_color		color_rgb;
	double		light_ratio;
	t_phong		phong;

	light_ratio = get_light_ratio(data, hit_point);
	if (light_ratio < 0)
		light_ratio = 0;
	// phong.ambient_color = get_ambient_color(data.sphere.color, data.ambient);
	phong.diffuse_color = get_diffuse_color(data.sphere.color, data.light, light_ratio);
	// color_rgb = add_all_phong_colors(phong);
	// return (color_rgb);
	return (phong.diffuse_color);
}
