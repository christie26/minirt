#include "../../includes/minirt.h"

t_camera	get_camera(char **tab, char *bit_mask)
{
	t_camera	camera;

	if (((*bit_mask & 2) == 2))
		error_msg(PARSE_CAMERA);
	camera.coordinate = get_coordinate(tab[1]);
	camera.vector = get_vector(tab[2]);
	camera.fov = get_double(tab[3]);
	if (tab[4])
		error_msg(PARSE_CAMERA);
	*bit_mask |= 2;
	return (camera);
}
