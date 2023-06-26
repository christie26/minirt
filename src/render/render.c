#include "../../includes/minirt.h"


int	win_close(void)
{
	exit (EXIT_SUCCESS);
}

int	render(t_data *data)
{
	// first_ppm(data);

	simple_render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	
	return (0);
}
