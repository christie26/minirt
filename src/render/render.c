#include "../../includes/minirt.h"


int	win_close(void)
{
	exit (EXIT_SUCCESS);
}

int	render(t_data *data)
{

	// destory the image if it exists
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);

	// create new image file and get infor to draw in image
	data->img = mlx_new_image(data->mlx, 1000, 1000);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	
	first_ppm(data);
	while (1);
	// have to change this function !!xs
	exit (EXIT_SUCCESS);
}
