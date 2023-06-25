
#include "../../includes/minirt.h"

t_cylinder	get_cylinder(char **tab)
{
	t_cylinder	cylinder;

	cylinder.cordinate = get_coordinate(tab[1]);
	cylinder.vector = get_vector(tab[2]);
	cylinder.diameter = get_double(tab[3]);
	cylinder.height = get_double(tab[4]);
	cylinder.color = get_color(tab[5]);
	return (cylinder);
}
