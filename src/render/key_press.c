#include "../../includes/minirt.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	else
		printf("key code is %d\n", keycode);
	if (keycode == UP)
		data->sphere.diameter *= 1.1;
	if (keycode == DOWN)
		data->sphere.diameter *= 0.9;
	// if (keycode == RIGHT)
	// 	data->y_ro -= 1;
	// (void)(data);
	return (0);
}