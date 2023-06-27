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

static t_color get_ambient_color(t_color obj_color, t_color ambient)
{
	t_color ambient_color;

	ambient_color = multiply_color(obj_color, ambient);
	return (ambient_color);
}

static t_color get_diffuse_color(t_color obj_color, t_color light_color, double light_ratio)
{
	t_color diffuse_color;

	diffuse_color = mix_color(obj_color, light_color, light_ratio);
	return (diffuse_color);
}

static double	get_light_ratio(t_data data, t_coordinate hit_point)
{
	t_vector	light_vector;
	double		light_ratio;

	light_vector = vector_unit(get_vector_two_point(data.light.coordinate, hit_point));
	light_ratio = vector_dot(light_vector, data.sphere.normal);
	return (light_ratio);
}

static t_color add_all_phong_colors(t_phong phong)
{
	t_color phong_color;

	phong_color = add_color(phong.ambient_color, phong.diffuse_color);
	return (phong_color);
}

t_color	apply_phong_model(t_data data, t_coordinate hit_point)
{
	t_color		color_rgb;
	double		light_ratio;
	t_phong		phong;

	light_ratio = get_light_ratio(data, hit_point);
	if (light_ratio < 0)
		light_ratio = 0;
	phong.ambient_color = get_ambient_color(data.sphere.color, data.ambient.color);
	phong.diffuse_color = get_diffuse_color(data.sphere.color, data.light.color, light_ratio);
	color_rgb = add_all_phong_colors(phong);
	return (color_rgb);
}
