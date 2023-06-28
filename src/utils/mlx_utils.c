#include "../../includes/minirt.h"

void	write_pixel_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 1920 || x < 0 || y > 1080 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return ;
}