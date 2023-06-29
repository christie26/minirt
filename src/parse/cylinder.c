
#include "../../includes/minirt.h"

t_cylinder	*get_cylinder(char **tab)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
		return (NULL);
	cylinder->coordinate = get_coordinate(tab[1]);
	cylinder->vector = get_vector(tab[2]);
	cylinder->diameter = get_double(tab[3]);
	cylinder->height = get_double(tab[4]);
	cylinder->color = get_color(tab[5]);
	return (cylinder);
}