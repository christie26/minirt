#include "../../includes/minirt.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	else
		printf("key code is %d\n", keycode);
	// if (keycode == LEFT)
	// 	data->y_ro += 1;
	// if (keycode == RIGHT)
	// 	data->y_ro -= 1;
	(void)(data);
	return (0);
}