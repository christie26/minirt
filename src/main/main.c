#include "../../includes/minirt.h"

// static void print_data(t_data data)
// {
// 	printf("print ambient ratio = %f\n", data.ambient.ratio);
// 	printf("print ambient color rgb = %d %d %d\n", data.ambient.color.red, data.ambient.color.green, data.ambient.color.blue);
// 	printf("print camera coordinate xyz = %f %f %f\n", data.camera.coordinate.x, data.camera.coordinate.y, data.camera.coordinate.z);
// 	printf("print camera vector xyz = %f %f %f\n", data.camera.vector.x, data.camera.vector.y, data.camera.vector.z);
// 	printf("print camera fov = %f\n", data.camera.fov);
// 	printf("print light coordinate xyz = %f %f %f\n", data.light.coordinate.x, data.light.coordinate.y, data.light.coordinate.z);
// 	printf("print light brightness = %f\n", data.light.brightness);
// 	printf("print light color rgb = %d %d %d\n", data.light.color.red, data.light.color.green, data.light.color.blue);
// 	printf("print sphere coordinate xyz = %f %f %f\n", data.sphere.coordinate.x, data.sphere.coordinate.y, data.sphere.coordinate.z);
// 	printf("print sphere diameter = %f\n", data.sphere.diameter);
// 	printf("print sphere color rgb = %d %d %d\n", data.sphere.color.red, data.sphere.color.green, data.sphere.color.blue);
// 	printf("print plane coordinate xyz = %f %f %f\n", data.plane.coordinate.x, data.plane.coordinate.y, data.plane.coordinate.z);
// 	printf("print plane vector xyz = %f %f %f\n", data.plane.vector.x, data.plane.vector.y, data.plane.vector.z);
// 	printf("print plane color rgb = %d %d %d\n", data.plane.color.red, data.plane.color.green, data.plane.color.blue);
// }

// void	leaks(void)
// {
// 	system("leaks minirt");
// }

int	main(int ac, char **av)
{
	t_data	data;

	// atexit(leaks);
	if (ac != 2)
	{
		error_msg(INVALID_ARGUMENT);
		return (EXIT_FAILURE);
	}
	data = parse_center(av[1]);
	// print_data(data);
	
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "Hello world!");
	data.img = mlx_new_image(data.mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
								&data.endian);
	 
	mlx_hook(data.win, 2, 0, key_press, &data);
	mlx_hook(data.win, 17, 0, win_close, 0);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);

	return (0);
}
