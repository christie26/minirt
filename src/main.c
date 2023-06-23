
#include "../include/parse.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
	{
		error_msg(INVALID_ARGUMENT);
		return (EXIT_FAILURE);
	}
	data = parse_center(av[1]);

	(void)(av);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	mlx_init(&data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 800, "minirt");
	mlx_hook(data->win, 2, 0, key_press, &data);
	mlx_hook(data->win, 17, 0, win_close, 0);
	mlx_loop_hook(data->mlx, render, &data);
	mlx_loop(data->mlx);
	return (0);
}
