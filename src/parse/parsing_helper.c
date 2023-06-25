
#include "../../includes/minirt.h"

t_coordinate	get_coordinate(char *coordinate_val)
{
	t_coordinate	coordinate;
	char		**coordinate_values;

	coordinate_values = ft_split(coordinate_val, ',');
	coordinate.x = get_double(coordinate_values[0]);
	coordinate.y = get_double(coordinate_values[1]);
	coordinate.z = get_double(coordinate_values[2]);
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
