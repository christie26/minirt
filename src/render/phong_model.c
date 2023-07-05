#include "../../includes/minirt.h"

static t_color	get_ambient_color(t_ambient ambient, t_ray *ray, t_screen screen)
{
	t_color	ambient_color;
	t_color	object_color;

	ambient_color = apply_brightness(ambient.color, ambient.ratio);
	object_color = get_obj_color(ray->object, ray->object_type, ray->hit_point, screen);
	ambient_color = multiply_color(object_color, ambient_color);
	return (ambient_color);
}

static t_color	get_diffuse_color(t_ray *ray, t_light light, \
		double light_ratio, t_screen screen)
{
	void *object;
	t_color		obj_color;
	t_color		diffuse_color;
	double		scala;

	object = ray->object;
	obj_color = get_obj_color(object, ray->object_type, ray->hit_point, screen);
	scala = light_ratio * light.brightness;
	diffuse_color = apply_brightness(light.color, scala);
	diffuse_color = multiply_color(diffuse_color, obj_color);
	return (diffuse_color);
}

static t_color	add_all_phong_colors(t_phong phong)
{
	t_color	phong_color;

	phong_color = add_color(phong.ambient_color, phong.diffuse_color);
	phong_color = add_color(phong_color, phong.specular_color);
	return (phong_color);
}

t_color	apply_phong_model(t_data data, t_ray *ray)
{
	t_color			color_rgb;
	double			light_ratio;
	t_phong			phong;
	t_coordinate	hit_point;

	hit_point = ray->hit_point;
	light_ratio = get_light_ratio(data, hit_point, ray);
	if (light_ratio < 0)
		light_ratio = 0;
	phong.ambient_color = get_ambient_color(data.ambient, ray, data.screen);
	phong.diffuse_color = get_diffuse_color(ray, data.light, \
			light_ratio, data.screen);
	phong.specular_color = get_specular_color(ray, data.light, \
			light_ratio);
	color_rgb = add_all_phong_colors(phong);
	return (color_rgb);
}
