/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xyz_rgv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:37:21 by minkim3           #+#    #+#             */
/*   Updated: 2023/06/24 21:37:36 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_cordinate	get_coordinate(char *cordinate_val)
{
	t_cordinate	cordinate;
	char		**cordinate_values;

	cordinate_values = ft_split(cordinate_val, ',');
	cordinate.x = get_double(cordinate_values[0]);
	cordinate.y = get_double(cordinate_values[1]);
	cordinate.z = get_double(cordinate_values[2]);
	free_two_dimensional_array(cordinate_values);
	return (cordinate);
}

t_color	get_color(char *color_val)
{
	t_color	color;
	char	**color_values;

	color_values = ft_split(color_val, ',');
	color.red = ft_atoi(color_values[0]);
	color.green = ft_atoi(color_values[1]);
	color.blue = ft_atoi(color_values[2]);
	free_two_dimensional_array(color_values);
	return (color);
}

t_vector	get_vector(char *vector_val)
{
	t_vector	vector;
	char		**vector_values;

	vector_values = ft_split(vector_val, ',');
	vector.x = get_double(vector_values[0]);
	vector.y = get_double(vector_values[1]);
	vector.z = get_double(vector_values[2]);
	free_two_dimensional_array(vector_values);
	return (vector);
}
