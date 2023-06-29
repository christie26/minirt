#include "../../includes/minirt.h"

static t_color	get_ambient_color(t_ambient ambient)
{
	t_color	ambient_color;

	ambient_color = apply_brightness(ambient.color, ambient.ratio);
	return (ambient_color);
}

static t_color	get_diffuse_color(t_list *shape, t_light light, \
		double light_ratio)
{
	t_node	*shape_node;
	t_color obj_color;
	t_color	diffuse_color;
	double		scala;

	shape_node = get_node(shape, shape->index);
	// if (shape_node->type == SPHERE)
	obj_color = ((t_sphere *)shape_node->shape)->color;
	scala = light_ratio * light.brightness;
	diffuse_color = apply_brightness(obj_color, scala);
	return (diffuse_color);
}

static double	get_light_ratio(t_data data, t_coordinate hit_point)
{
	double		light_ratio;
	t_ray		hit_to_light;
	t_vector	normal;
	t_node		*shapes;
	void		*shape;

	shapes = get_node(data.shapes, data.shapes->index);
	shape = shapes->shape;
	hit_to_light.origin = hit_point;
	hit_to_light.direction = vector_unit(get_vector_two_point(hit_point, \
				data.light.coordinate));
	fix_hit_to_light(&hit_to_light);
	if (is_shadow(data, hit_to_light))
		return (0);
	// if (shapes->type == SPHERE)
	normal = vector_unit(get_vector_two_point(((t_sphere *)shape)->center, hit_point));
	light_ratio = vector_dot(normal, hit_to_light.direction);
	return (light_ratio);
}

static t_color	add_all_phong_colors(t_phong phong)
{
	t_color	phong_color;

	phong_color = add_color(phong.ambient_color, phong.diffuse_color);
	return (phong_color);
}

t_color	apply_phong_model(t_data data, t_coordinate hit_point)
{
	t_color	color_rgb;
	double	light_ratio;
	t_phong	phong;

	light_ratio = get_light_ratio(data, hit_point);
	if (light_ratio < 0)
		light_ratio = 0;
	phong.ambient_color = get_ambient_color(data.ambient);
	phong.diffuse_color = get_diffuse_color(data.shapes, data.light, \
			light_ratio);
	color_rgb = add_all_phong_colors(phong);
	return (color_rgb);
}
