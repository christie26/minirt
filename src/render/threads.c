#include "../../includes/minirt.h"

void	make_threads(t_data *data, pthread_t threads[],
		t_render_thread thread_data[])
{
	int				index;
	int				block_width;
	int				block_height;
	int				i;
	int				j;
	t_render_thread	*td;

	index = 0;
	block_width = WINDOW_WIDTH / THREADS_PER_DIMENSION;
	block_height = WINDOW_HEIGHT / THREADS_PER_DIMENSION;
	i = 0;
	while (i < THREADS_PER_DIMENSION)
	{
		j = 0;
		while (j < THREADS_PER_DIMENSION)
		{
			td = &thread_data[index];
			td->data = data;
			td->start_x = j * block_width;
			td->end_x = (j + 1) * block_width;
			td->start_y = i * block_height;
			td->end_y = (i + 1) * block_height;
			td->thread_index = index;
			if (j == THREADS_PER_DIMENSION - 1)
				td->end_x = WINDOW_WIDTH;
			if (i == THREADS_PER_DIMENSION - 1)
				td->end_y = WINDOW_HEIGHT;
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
