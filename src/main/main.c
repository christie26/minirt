/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:51:38 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:51:38 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	add_mlx_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, \
			"miniRT");
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

int	main(int ac, char **av)
{
	t_data			data;
	pthread_t		*threads;
	t_render_thread	*thread_data;

	threads = malloc(NUM_THREADS * sizeof(pthread_t));
	thread_data = malloc(NUM_THREADS * sizeof(t_render_thread));
	if (ac != 2)
	{
		error_msg(INVALID_ARGUMENT);
		return (EXIT_FAILURE);
	}
	data = parse_center(av[1]);
	add_mlx_data(&data);
	setup_screen(&data);
	make_threads(&data, threads, thread_data);
	join_threads(threads);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 0, key_press, &data);
	mlx_hook(data.win, 17, 0, win_close, 0);
	mlx_loop(data.mlx);
	destroy_list(&data.object_list);
	destroy_list(&data.light_list);
	free(threads);
	free(thread_data);
	return (0);
}
