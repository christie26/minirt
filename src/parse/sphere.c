
#include "../../includes/minirt.h"

t_sphere	get_sphere(char **tab)
{
	t_sphere	sphere;

	sphere.coordinate = get_coordinate(tab[1]);
	sphere.diameter = get_double(tab[2]);
	sphere.color = get_color(tab[3]);
	return (sphere);
}
