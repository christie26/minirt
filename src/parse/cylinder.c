#include "../../includes/minirt.h"

void	get_arguments(t_cylinder *cylinder, char **tab)
{
	cylinder->base = get_coordinate(tab[1]);
	cylinder->vector = vector_unit(get_vector(tab[2]));
	cylinder->diameter = get_double(tab[3]);
	cylinder->height = get_double(tab[4]);
	cylinder->color = get_color(tab[5]);
	cylinder->checker = 0;
}

t_cylinder	*get_cylinder(char **tab)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
		return (NULL);
	if (!tab[1] || !tab[2] || !tab[3] || !tab[4] || !tab[5])
		error_msg(LACK_ELEMENT);
	get_arguments(cylinder, tab);
	if (tab[6])
	{
		if (!ft_strcmp(tab[6], "ch"))
			cylinder->checker = 1;
		else
			error_msg(PARSE_CYLINDER);
		if (tab[7])
			error_msg(PARSE_CYLINDER);
	}
	cylinder->top = add_coordinates(cylinder->base, \
		vector_to_coordinate(vector_mult_scalar(cylinder->vector, \
			cylinder->height)));
	return (cylinder);
}
