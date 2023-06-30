#include "../../includes/minirt.h"

static t_color sky_color(t_ray ray, double vertical)
{
    t_color     color_rgb;
    double      ratio;

    ratio = (ray.direction.y + vertical) / (2 * vertical);
    color_rgb = mix_color(get_color("255,255,255"), get_color("30,144,255"), ratio);
    return (color_rgb);
}

static double	get_short_distance(t_list *object_list, t_ray *ray)
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
		if (node->type == SPHERE)
		{
			hit_point = get_closer_sphere_point(*(t_sphere *)object, ray);
			if (is_same_coordinate(hit_point, ray->origin))
				return (INFINITY);
		}
		// else if (object->type == PLANE)
			// distance = get_closer_plane_point(*(t_plane *)object->object, ray);
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
	printf("check obj list\n");
	printf("obj 1 = %d\n", ((t_sphere*)(data->object_list->headnode->object))->color.red);
	printf("obj 2 = %d\n", ((t_sphere*)(data->object_list->headnode->next->object))->color.red);
	if (get_short_distance(data->object_list, ray) == INFINITY)
		return (background_color);
	// t_color color = ((t_sphere*)(ray->object))->color;
	// printf("object color %d,%d,%d\n0", color.red, color.green, color.blue);
	return (apply_phong_model(*data, ray));
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
