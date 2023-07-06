#include "../../includes/minirt.h"

t_ambient	get_ambient(char **tab, char *bit_mask)
{
	t_ambient	ambient;

	if ((*bit_mask & 1) == 1)
		error_msg(PARSE_AMBIENT);
	if (!tab[1] || !tab[2])
		error_msg(LACK_ELEMENT);
	ambient.ratio = get_double(tab[1]);
	ambient.color = get_color(tab[2]);
	if (tab[3])
		error_msg(PARSE_AMBIENT);
	*bit_mask |= 1;
	return (ambient);
}
