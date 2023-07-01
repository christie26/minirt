#include "../../includes/minirt.h"

t_light	get_light(char **tab, char *bit_mask)
{
	t_light	light;

	if ((*bit_mask & 4) == 4)
		error_msg(PARSE_LIGHT);
	light.coordinate = get_coordinate(tab[1]);
	light.brightness = get_double(tab[2]);
	light.color = get_color(tab[3]);
	if (tab[4])
		error_msg(PARSE_LIGHT);
	*bit_mask |= 4;
	return (light);
}
