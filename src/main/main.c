/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:07:49 by minkim3           #+#    #+#             */
/*   Updated: 2023/06/24 21:56:40 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// static void print_data(t_data data)
// {
// 	printf("print ambient ratio = %f\n", data.ambient.ratio);
// 	printf("print ambient color rgb = %d %d %d\n", data.ambient.color.red, data.ambient.color.green, data.ambient.color.blue);
// 	printf("print camera cordinate xyz = %f %f %f\n", data.camera.cordinate.x, data.camera.cordinate.y, data.camera.cordinate.z);
// 	printf("print camera vector xyz = %f %f %f\n", data.camera.vector.x, data.camera.vector.y, data.camera.vector.z);
// 	printf("print camera fov = %f\n", data.camera.fov);
// 	printf("print light cordinate xyz = %f %f %f\n", data.light.cordinate.x, data.light.cordinate.y, data.light.cordinate.z);
// 	printf("print light brightness = %f\n", data.light.brightness);
// 	printf("print light color rgb = %d %d %d\n", data.light.color.red, data.light.color.green, data.light.color.blue);
// 	printf("print sphere cordinate xyz = %f %f %f\n", data.sphere.cordinate.x, data.sphere.cordinate.y, data.sphere.cordinate.z);
// 	printf("print sphere diameter = %f\n", data.sphere.diameter);
// 	printf("print sphere color rgb = %d %d %d\n", data.sphere.color.red, data.sphere.color.green, data.sphere.color.blue);
// 	printf("print plane cordinate xyz = %f %f %f\n", data.plane.cordinate.x, data.plane.cordinate.y, data.plane.cordinate.z);
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
	// (void)(av);
	// data = ft_calloc(1, sizeof(t_data));
	// if (!data)
	// 	return (EXIT_FAILURE);
	// mlx_init(&data);
	// data->mlx = mlx_init();
	// data->win = mlx_new_window(data->mlx, 1000, 800, "minirt");
	// mlx_hook(data->win, 2, 0, key_press, &data);
	// mlx_hook(data->win, 17, 0, win_close, 0);
	// mlx_loop_hook(data->mlx, render, &data);
	// mlx_loop(data->mlx);
	return (0);
}
