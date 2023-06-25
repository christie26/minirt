
#include "../../includes/minirt.h"

t_light	get_light(char **tab)
{
	t_light	light;

	light.cordinate = get_coordinate(tab[1]);
	light.brightness = get_double(tab[2]);
	light.color = get_color(tab[3]);
	return (light);
}
