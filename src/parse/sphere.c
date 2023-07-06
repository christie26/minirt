#include "../../includes/minirt.h"

t_sphere	*get_sphere(char **tab)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (sphere == NULL)
		exit(EXIT_FAILURE);
	sphere->center = get_coordinate(tab[1]);
	sphere->diameter = get_double(tab[2]);
	sphere->color = get_color(tab[3]);
	if (tab[4])
	{
		if (ft_strcmp(tab[4], "ch"))
			sphere->checker = 1;
		else
			error_msg(PARSE_SPHERE);
		if (tab[5])
			error_msg(PARSE_SPHERE);
	}
	return (sphere);
}
