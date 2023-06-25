
#include "../../includes/minirt.h"

t_plane	get_plane(char **tab)
{
	t_plane	plane;

	plane.cordinate = get_coordinate(tab[1]);
	plane.vector = get_vector(tab[2]);
	plane.color = get_color(tab[3]);
	return (plane);
}
