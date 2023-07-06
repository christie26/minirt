#include "../../includes/minirt.h"

t_plane	*get_plane(char **tab)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (plane == NULL)
		exit(EXIT_FAILURE);
	if (!tab[1] || !tab[2] || !tab[3])
		error_msg(LACK_ELEMENT);
	plane->coordinate = get_coordinate(tab[1]);
	plane->vector = vector_unit(get_vector(tab[2]));
	plane->color = get_color(tab[3]);
	if (tab[4])
	{
		if (ft_strcmp(tab[4], "ch"))
			plane->checker = 1;
		else
			error_msg(PARSE_PLANE);
		if (tab[5])
			error_msg(PARSE_PLANE);
	}
	return (plane);
}
