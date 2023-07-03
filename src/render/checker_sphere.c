#include "../../includes/minirt.h"

t_color	get_checkerboard_sphere(t_sphere sphere, t_coordinate hit_point, t_screen screen)
{
	t_vector	center_to_hit;
	t_vector	xy_plane;
	t_vector	z_axis;
	double		xy_angle;
	double		z_angle;

	center_to_hit = get_vector_two_point(sphere.center, hit_point);
	xy_plane = screen.vertical;
	z_axis = screen.horizontal;
	xy_angle = radian_to_degree((vector_dot(xy_plane, center_to_hit) / vector_length(center_to_hit))) + 360;
	z_angle = radian_to_degree((vector_dot(z_axis, center_to_hit) / vector_length(center_to_hit))) + 180;

	if (dmod(xy_angle,30) > 0 && dmod(xy_angle,30) < 15)
	{
		if (dmod(z_angle,30) > 0 && dmod(z_angle,30) < 15)
			return (get_color("255,255,255"));
		else
			return (get_color("0,0,0"));
	}
	else
	{
		if (dmod(z_angle,30) > 0 && dmod(z_angle,30) < 15)
			return (get_color("0,0,0"));
		else
			return (get_color("255,255,255"));
	}
	return (sphere.color);
}