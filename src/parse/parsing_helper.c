/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:50:06 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:50:07 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_coordinate	get_coordinate(char *coordinate_val)
{
	t_coordinate	coordinate;
	char			**coordinate_values;

	coordinate_values = ft_split(coordinate_val, ',');
	if (!coordinate_values)
		error_msg(MALLOC_ERROR);
	else if (!coordinate_values[0] || !coordinate_values[1] \
			|| !coordinate_values[2])
		error_msg(PARSE_COORDINATE);
	coordinate.x = get_double(coordinate_values[0]);
	coordinate.y = get_double(coordinate_values[1]);
	coordinate.z = get_double(coordinate_values[2]);
	if (coordinate_values[3])
		error_msg(PARSE_COORDINATE);
	free_two_dimensional_array(coordinate_values);
	return (coordinate);
}

t_coordinate	get_coordinate_double(double x, double y, double z)
{
	t_coordinate	coordinate;

	coordinate.x = x;
	coordinate.y = y;
	coordinate.z = z;
	return (coordinate);
}

t_color	get_color(char *color_val)
{
	t_color	color;
	char	**color_values;

	color_values = ft_split(color_val, ',');
	if (!color_values)
		error_msg(MALLOC_ERROR);
	else if (!color_values[0] || !color_values[1] || !color_values[2])
		error_msg(PARSE_COLOR);
	color.red = ft_atoi(color_values[0]);
	color.green = ft_atoi(color_values[1]);
	color.blue = ft_atoi(color_values[2]);
	if (color_values[3])
		error_msg(PARSE_COLOR);
	if (color.red < 0 || color.red > 255 || color.green < 0 || \
		color.green > 255 || color.blue < 0 || color.blue > 255)
		error_msg(PARSE_COLOR);
	free_two_dimensional_array(color_values);
	return (color);
}

t_vector	get_vector(char *vector_val)
{
	t_vector	vector;
	char		**vector_values;
	double		size_of_vector;

	vector_values = ft_split(vector_val, ',');
	if (!vector_values)
		error_msg(MALLOC_ERROR);
	else if (!vector_values[0] || !vector_values[1] || !vector_values[2])
		error_msg(PARSE_VECTOR);
	vector.x = get_double(vector_values[0]);
	vector.y = get_double(vector_values[1]);
	vector.z = get_double(vector_values[2]);
	// if (vector.x < -1 || vector.x > 1 || vector.y < -1 || \
	// 	vector.y > 1 || vector.z < -1 || vector.z > 1)
	// 	error_msg(PARSE_VECTOR);
	if (vector_values[3])
		error_msg(PARSE_VECTOR);
	size_of_vector = vector_length(vector);
	// if (size_of_vector > 1.01 || size_of_vector < 0.99)
	// 	error_msg(PARSE_VECTOR);
	free_two_dimensional_array(vector_values);
	return (vector);
}
