#include "../../includes/minirt.h"

t_light	*get_light(char **tab)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	light->coordinate = get_coordinate(tab[1]);
	light->brightness = get_double(tab[2]);
	light->color = get_color(tab[3]);
	if (tab[4])
		error_msg(PARSE_LIGHT);
	return (light);
}
