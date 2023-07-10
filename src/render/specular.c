#include "../../includes/minirt.h"

// R = 2*(N.L)*N - L
// I = k * dot(R, V)^n
static t_vector	get_reflected_light(t_ray *ray)
{
	t_vector	reflected_light;
	t_vector	normal;
	t_vector	light_direction;
	double		light_ratio;

	normal = ray->hit_normal;
	light_direction = vector_unit(ray->hit_direction);
	light_ratio = vector_dot(normal, light_direction);
	reflected_light = vector_sub(vector_mult_scalar(normal, 2 * light_ratio), \
									ray->hit_direction);
	return (reflected_light);
}

// 2 * (N dot L) * N - L
t_color	get_specular_color(t_ray *ray, t_light *light, double light_ratio)
{
	double				shininess;
	t_color				specular_color;
	t_specular_light	specular;

	if (light_ratio <= 0)
		return (get_color("0,0,0"));
	shininess = 50;
	specular.reflected_light = vector_unit(get_reflected_light(ray));
	specular.viewer_direction = vector_unit(vector_mult_scalar(ray->direction, \
				-1));
	specular.specular_ratio = fmax(0.0, vector_dot(specular.reflected_light, \
				specular.viewer_direction));
	specular.specular_intensity = pow(specular.specular_ratio, shininess);
	specular_color = apply_brightness(light->color, \
										specular.specular_intensity);
	return (specular_color);
}
