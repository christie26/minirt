
#include "../../includes/minirt.h"

t_camera	get_camera(char **tab)
{
	t_camera	camera;

	camera.cordinate = get_coordinate(tab[1]);
	camera.vector = get_vector(tab[2]);
	camera.fov = get_double(tab[3]);
	return (camera);
}
