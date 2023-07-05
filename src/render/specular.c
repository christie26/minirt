#include "../../includes/minirt.h"

	// R = 2*(N.L)*N - L
	// I = k * dot(R, V)^n
t_color	get_specular_color(t_ray *ray, t_light *light, double light_ratio)
{
	t_vector	reflected_light;
	t_vector	viewer_direction;
	double		specular_intensity;
	t_color		specular_color;
	double		shininess;
	double		ambient_ratio;

	if (light_ratio <= 0)
		return (get_color("0,0,0"));
	reflected_light = vector_sub(vector_mult_scalar(ray->hit_normal, 2 \
				* vector_dot(ray->hit_normal, ray->hit_direction)), ray->hit_direction);
	viewer_direction = vector_mult_scalar(ray->direction, -1);
	shininess = 50;
	ambient_ratio = vector_dot(vector_unit(reflected_light), vector_unit(viewer_direction));
	if (ambient_ratio < 0)
		specular_intensity = 0;
	else
		specular_intensity = pow(ambient_ratio, shininess);
	specular_color = apply_brightness(light->color, specular_intensity);
	return (specular_color);
}
