#include "../../includes/minirt.h"

static t_color	sky_color(t_ray ray)
{
	t_color		color_rgb;
	t_vector	unit_vector;
	double		ratio;

	unit_vector = vector_unit(ray.direction);
	ratio = 0.5 * (unit_vector.y + 1);
	color_rgb = mix_color(get_color("255,255,255"), get_color("30,144,255"), \
			ratio);
	return (color_rgb);
}

static t_coordinate	get_shape_point(t_data *data, t_list *shape, t_ray ray)
{
	t_coordinate	hit_point;
	t_coordinate	closer_hit_point;
	t_node			*tmp;
	int				index;

	tmp = shape->headnode;
	index = 0;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			hit_point = get_closer_sphere_point(*(t_sphere *)tmp->shape, ray);
		closer_hit_point = get_closer_point(hit_point, closer_hit_point, ray);
		tmp = tmp->next;
		if (tmp)
			index++;
	}

	shape->index = index;
	data->shapes = shape;
	return (closer_hit_point);
}

static t_color	get_color_rgb(t_ray ray, t_data *data)
{
	t_coordinate	hit_point;
	t_color			background_color;

	hit_point.x = INFINITY;
	background_color = sky_color(ray);
	hit_point = get_shape_point(data, data->shapes, ray);
	if (hit_point.x == INFINITY)
		return (background_color);
	return (apply_phong_model(*data, hit_point));
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
	for (int j = WINDOW_HEIGHT - 1; j >= 0; --j)
	{
		for (int i = 0; i < WINDOW_WIDTH; ++i)
		{
			u = (double)(i) / (WINDOW_WIDTH - 1);
			v = (double)(j) / (WINDOW_HEIGHT - 1);
			ray.origin = data->camera.coordinate;
			ray.direction = get_ray_direction(screen.start_point,\
				screen.horizontal, screen.vertical,data->camera.coordinate, \
				u, v);
			color_rgb = get_color_rgb(ray, data);
			color_hex = color_to_hex(color_rgb);
			write_pixel_image(data, i, j, color_hex);
		}
	}
}
