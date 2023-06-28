#include "../../includes/minirt.h"

static t_color get_ambient_color(t_ambient ambient)
{
	t_color ambient_color;

	ambient_color = apply_brightness(ambient.color, ambient.ratio);
	return (ambient_color);
}

static t_color get_diffuse_color(t_color obj_color, t_light light, double light_ratio)
{
	t_color diffuse_color;
	t_color light_brightness_color;

	light_brightness_color = apply_brightness(light.color, light.brightness);
	light_brightness_color = apply_brightness(light_brightness_color, light_ratio);
	diffuse_color = multiply_color(obj_color, light_brightness_color);
	return (diffuse_color);
}

// 나중에 도형 여러개로 확장할 함수
static int	is_shadow(t_data data, t_ray ray_to_light)
{
	if (hit_sphere(data.sphere, ray_to_light))
		return (1);
	return (0);
}

//이거... 
static double	get_light_ratio(t_data data, t_coordinate hit_point)
{
	double		light_ratio;
	t_ray		hit_to_light;
	t_vector	normal;

	hit_to_light.origin = hit_point;
	hit_to_light.direction = vector_unit(get_vector_two_point(hit_point, data.light.coordinate));
	if (is_shadow(data, hit_to_light))
		return (0);
	normal = vector_unit(get_vector_two_point(data.sphere.center, hit_point));
	light_ratio = vector_dot(normal, hit_to_light.direction);
	// printf("h_p(%.2f,%.2f,%.2f)")
	light_ratio *= -1;  // 지워야 함
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
	phong.ambient_color = get_ambient_color(data.ambient);
	phong.diffuse_color = get_diffuse_color(data.sphere.color, data.light, light_ratio);
	color_rgb = add_all_phong_colors(phong);
	return (color_rgb);
}
