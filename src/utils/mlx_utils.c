#include "../../includes/minirt.h"

void	write_pixel_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WINDOW_WIDTH || x < 0 || y > WINDOW_HEIGHT || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return ;
}

int	win_close(void)
{
	exit(EXIT_SUCCESS);
}
