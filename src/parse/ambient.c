
#include "../../includes/minirt.h"

t_ambient	get_ambient(char **tab)
{
	t_ambient	ambient;

	ambient.ratio = get_double(tab[1]);
	ambient.color = get_color(tab[2]);
	return (ambient);
}
