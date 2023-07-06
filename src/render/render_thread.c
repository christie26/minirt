#include "../../includes/minirt.h"

static t_color sky_color(t_ray ray, double vertical)
{
    t_color     color_rgb;
    double      ratio;

    ratio = (ray.direction.x + vertical) / (2 * vertical);
    color_rgb = mix_color(get_color("255,255,255"), get_color("30,144,255"), ratio);
    return (color_rgb);
}

static t_color	get_color_rgb(t_ray *ray, t_data *data)
{
	t_color			background_color;

	background_color = sky_color(*ray, data->screen.view_height);
	if (get_short_distance(data->object_list, ray) == INFINITY)
		return (background_color);
	return (apply_phong_model_to_all_lights(*data, ray));
}

void* render_thread(void* arg) {
    t_render_thread* thread_data = (t_render_thread*)arg;
    int x = thread_data->start_x;
    int y = thread_data->start_y;
    t_ray ray;
    t_color color_rgb;
    int color_hex;

	printf("start_x: %d, end_x: %d, start_y: %d, end_y: %d\n", thread_data->start_x, thread_data->end_x, thread_data->start_y, thread_data->end_y);
	printf("thread_index = %d\n", thread_data->thread_index);
    while (y < thread_data->end_y) {
        x = thread_data->start_x;
        while (x < thread_data->end_x) {
            double u = (double)(x - thread_data->start_x) / (thread_data->end_x - thread_data->start_x);
            double v = (double)(y - thread_data->start_y) / (thread_data->end_y - thread_data->start_y);
 			// double u = (double)(x - thread_data->start_x) / (WINDOW_WIDTH - 1);
            // double v = (double)(y - thread_data->start_y) / (WINDOW_HEIGHT - 1);
            ray.origin = thread_data->data->camera.coordinate;
            ray.direction = get_ray_direction(thread_data->data->screen.start_point, \
				thread_data->data->screen.horizontal, \
					thread_data->data->screen.vertical, \
						thread_data->data->camera.coordinate, u, v);
            color_rgb = get_color_rgb(&ray, thread_data->data);
            color_hex = color_to_hex(color_rgb);
            write_pixel_image(thread_data->data, x, y, color_hex);
            x++;
        }
        y++;
    }

    return NULL;
}

void	make_threads(t_data *data, pthread_t threads[], \
		t_render_thread thread_data[])
{
	int				count;
	int				block_width;
	int				block_height;
	int				i;
	int				j;
	t_render_thread	*td;

	count = 0; // Start the thread count from 0
	block_width = WINDOW_WIDTH / THREADS_PER_DIMENSION; // Divide the window width and height
	block_height = WINDOW_HEIGHT / THREADS_PER_DIMENSION;
	i = 0;
	while (i < THREADS_PER_DIMENSION)
	{
		j = 0;
		while (j < THREADS_PER_DIMENSION)
		{
			td = &thread_data[count];
			td->data = data;
			td->start_x = j * block_width;
			td->end_x = (j + 1) * block_width;
			td->start_y = i * block_height;
			td->end_y = (i + 1) * block_height;
			td->thread_index = count;
			if (j == THREADS_PER_DIMENSION - 1)
				td->end_x = WINDOW_WIDTH;
			if (i == THREADS_PER_DIMENSION - 1)
				td->end_y = WINDOW_HEIGHT;
			pthread_create(&threads[count], NULL, render_thread, td);
			j++;
			count++;
		}
		i++;
	}
}

void	join_threads(pthread_t threads[])
{
	int	count;

	count = 0;
	while (count < NUM_THREADS)
	{
		pthread_join(threads[count], NULL);
		count++;
	}
}
