#include "../../includes/minirt.h"

int	win_close(void)
{
	exit(EXIT_SUCCESS);
}


static t_color	sky_color(t_ray ray, double vertical)
{
	t_color	color_rgb;
	double	ratio;

	ratio = (ray.direction.x + vertical) / (2 * vertical);
	color_rgb = mix_color(get_color("255,255,255"), get_color("30,144,255"),
			ratio);
	return (color_rgb);
}

static t_color	get_color_rgb(t_ray *ray, t_data *data)
{
	t_color	background_color;

	background_color = sky_color(*ray, data->screen.view_height);
	if (get_short_distance(data->object_list, ray) == INFINITY)
		return (background_color);
	return (apply_phong_model_to_all_lights(*data, ray));
}

void	*render_thread(void *arg)
{
	t_render_thread	*thread_data;
	int				x;
	int				y;
	t_ray			ray;
	t_color			color_rgb;
	int				color_hex;
	double			u;
	double			v;

	thread_data = (t_render_thread *)arg;
	x = thread_data->start_x;
	y = thread_data->start_y;
	while (y < thread_data->end_y)
	{
		x = thread_data->start_x;
		while (x < thread_data->end_x)
		{
			u = (double)(x) / WINDOW_WIDTH;
			v = (double)(y) / WINDOW_HEIGHT;
			ray.origin = thread_data->data->camera.coordinate;
			ray.direction = get_ray_direction(thread_data->data->screen.start_point, \
				thread_data->data->screen.horizontal, thread_data->data->screen.vertical, \
					thread_data->data->camera.coordinate, u, v);
			color_rgb = get_color_rgb(&ray, thread_data->data);
			color_hex = color_to_hex(color_rgb);
			write_pixel_image(thread_data->data, x, y, color_hex);
			x++;
		}
		y++;
	}
	return (NULL);
}
