#include "../../includes/minirt.h"

t_color	get_checkerboard_cylinder(t_cylinder cylinder, t_coordinate hit_point)
{
	t_vector	vertical;
	t_vector	horizontal;
	t_vector	point_to_hit;
	double		vertical_len;
	double		horizontal_len;

	vertical = get_world_vertical(cylinder.vector);
	horizontal = vector_cross(cylinder.vector, vertical);
	point_to_hit = get_vector_two_point(cylinder.coordinate, hit_point);
	vertical_len = vector_dot(point_to_hit, vertical) / vector_length(vertical) + 1000;
	horizontal_len = vector_dot(point_to_hit, horizontal) / vector_length(horizontal) + 1000;
	if (!cylinder.checker)
		return (cylinder.color);
	return (cylinder.color);
	if (dmod(vertical_len, 1) > 0 && dmod(vertical_len, 1) < 0.5)
	{
		if (dmod(horizontal_len, 1) > 0 && dmod(horizontal_len, 1) < 0.5)
			return (cylinder.color);
		else
			return (get_color("0,0,0"));
	}
	else
	{
		if (dmod(horizontal_len, 1) > 0 && dmod(horizontal_len, 1) < 0.5)
			return (get_color("0,0,0"));
		else
			return (cylinder.color);
	}
}