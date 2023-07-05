#include "../../includes/minirt.h"

static t_color sky_color(t_ray ray, double vertical)
{
    t_color     color_rgb;
    double      ratio;

    ratio = (ray.direction.x + vertical) / (2 * vertical);
    color_rgb = mix_color(get_color("255,255,255"), get_color("30,144,255"), ratio);
    return (color_rgb);
}

double	get_short_distance(t_list *object_list, t_ray *ray)
{
	t_node			*node;
	double			short_distance;
	t_coordinate	hit_point;
	void			*object;

	node = object_list->headnode;
	short_distance = INFINITY;
	while (node)
	{
		object = node->object;
		hit_point = get_hit_point(ray, node);
		if (short_distance > get_distance(hit_point, ray->origin))
		{
			ray->object = object;
			ray->object_type = node->type;
			ray->hit_point = hit_point;
			short_distance = get_distance(hit_point, ray->origin);
		}
		node = node->next;
	}
	return (short_distance);
}

static t_color	get_color_rgb(t_ray *ray, t_data *data)
{
	t_color			background_color;

	background_color = sky_color(*ray, data->screen.view_height);
	if (get_short_distance(data->object_list, ray) == INFINITY)
		return (background_color);
	return (apply_phong_model_to_all_lights(*data, ray));
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
			color_rgb = get_color_rgb(&ray, data);
			color_hex = color_to_hex(color_rgb);
			write_pixel_image(data, i, j, color_hex);
		}
	}
}
