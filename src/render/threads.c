#include "../../includes/minirt.h"

static t_render_thread	*get_data(t_render_thread *td, t_data *data, int index, \
		t_render_thread thread_data[])
{
	td = &thread_data[index];
	td->data = data;
	td->thread_index = index;
	return (td);
}

static void	get_screen_data(t_render_thread *td, int i, int j)
{
	int	block_width;
	int	block_height;

	block_width = WINDOW_WIDTH / THREADS_PER_DIMENSION;
	block_height = WINDOW_HEIGHT / THREADS_PER_DIMENSION;
	td->start_x = j * block_width;
	td->end_x = (j + 1) * block_width;
	td->start_y = i * block_height;
	td->end_y = (i + 1) * block_height;
	if (j == THREADS_PER_DIMENSION - 1)
		td->end_x = WINDOW_WIDTH;
	if (i == THREADS_PER_DIMENSION - 1)
		td->end_y = WINDOW_HEIGHT;
}

void	make_threads(t_data *data, pthread_t threads[],
		t_render_thread thread_data[])
{
	int				index;
	int				i;
	int				j;
	t_render_thread	*td;

	index = 0;
	i = 0;
	while (i < THREADS_PER_DIMENSION)
	// while (i < 1)
	{
		j = 0;
		while (j < THREADS_PER_DIMENSION)
		{
			td = get_data(td, data, index, thread_data);
			get_screen_data(td, i, j);
			pthread_create(&threads[index], NULL, render_thread, td);
			j++;
			index++;
		}
		i++;
	}
}

void	join_threads(pthread_t threads[])
{
	int	index;

	index = 0;
	while (index < NUM_THREADS)
	{
		pthread_join(threads[index], NULL);
		index++;
	}
}
