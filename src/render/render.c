#include "../../includes/minirt.h"

static t_color	sky_color(t_ray ray, double vertical)
{
	t_color	color_rgb;
	double	ratio;

	ratio = (ray.direction.x + vertical) / (2 * vertical);
	color_rgb = mix_color(get_color("255,255,255"), get_color("30,144,255"), \
			ratio);
	return (color_rgb);
}

static t_vector	get_ray_direction(t_render info)
{
	t_vector		ray_direction;
	t_coordinate	pixel;

	pixel.x = info.lower_left_corner.x + info.u * info.horizontal.x + info.v \
		* info.vertical.x;
	pixel.y = info.lower_left_corner.y + info.u * info.horizontal.y + info.v \
		* info.vertical.y;
	pixel.z = info.lower_left_corner.z + info.u * info.horizontal.z + info.v \
		* info.vertical.z;
	ray_direction = get_vector_two_point(info.origin, pixel);
	return (ray_direction);
}

t_color	get_color_rgb(t_ray *ray, t_data *data)
{
	t_color	background_color;

	background_color = sky_color(*ray, data->screen.view_height);
	if (get_short_distance(data->object_list, ray) == INFINITY)
		return (background_color);
	return (apply_phong_model_to_all_lights(*data, ray));
}

static t_render	get_render_info(t_data *data, int x, int y)
{
	t_render	info;

	info.u = (double)(x) / WINDOW_WIDTH;
	info.v = (double)(y) / WINDOW_HEIGHT;
	info.lower_left_corner = data->screen.start_point;
	info.horizontal = data->screen.horizontal;
	info.vertical = data->screen.vertical;
	info.origin = data->camera.coordinate;
	return (info);
}

void	*render_thread(void *arg)
{
	t_render_thread	*thread_data;
	int				x;
	int				y;
	t_ray			ray;
	t_render		info;

	thread_data = (t_render_thread *)arg;
	x = thread_data->start_x;
	y = thread_data->start_y;
	while (y < thread_data->end_y)
	{
		x = thread_data->start_x;
		while (x < thread_data->end_x)
		{
			info = get_render_info(thread_data->data, x, y);
			ray.origin = thread_data->data->camera.coordinate;
			ray.direction = get_ray_direction(info);
			info.color_rgb = get_color_rgb(&ray, thread_data->data);
			info.color_hex = color_to_hex(info.color_rgb);
			write_pixel_image(thread_data->data, x, y, info.color_hex);
			x++;
		}
		y++;
	}
	return (NULL);
}
