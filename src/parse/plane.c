#include "../../includes/minirt.h"

t_plane	*get_plane(char **tab)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (plane == NULL)
		exit(EXIT_FAILURE);
	plane->coordinate = get_coordinate(tab[1]);
	plane->vector = get_vector(tab[2]);
	plane->color = get_color(tab[3]);
	if (tab[4])
		error_msg(PARSE_PLANE);
	return (plane);
}
