#include "../../includes/minirt.h"

static t_color	ray_sky_color(t_ray ray)
{
	double		ratio;
	t_color		color_rgb;
	t_vector	unit_vector;

	unit_vector = vector_unit(ray.direction);
	ratio = 0.5 * (unit_vector.y + 1);
	color_rgb = gredient_color(get_color("255,255,255"), \
			get_color("30,144,255"), ratio);
	return (color_rgb);
}

t_color	get_color_rgb(t_ray ray, t_data *data)
{
	if (hit_sphere(data->sphere, ray))
		return (data->sphere.color);
	else
		return (ray_sky_color(ray));
}