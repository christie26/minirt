#include "../../includes/minirt.h"

static t_color sky_color(t_ray ray, double vertical)
{
    t_color     color_rgb;
    double      ratio;

    ratio = (ray.direction.y + vertical) / (2 * vertical);
    color_rgb = mix_color(get_color("255,255,255"), get_color("30,144,255"), ratio);
    return (color_rgb);
}

static t_coordinate	get_shape_point(t_data *data, t_list *shape, t_ray ray)
{
	t_coordinate	hit_point;
	t_coordinate	closer_hit_point;
	t_node			*tmp;
	int				index;

	tmp = shape->headnode;
	index = 0;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			hit_point = get_closer_sphere_point(*(t_sphere *)tmp->shape, ray);
		closer_hit_point = get_closer_point(hit_point, closer_hit_point, ray);
		tmp = tmp->next;
		if (tmp)
			index++;
	}

	shape->index = index;
	data->shapes = shape;
	return (closer_hit_point);
}

static t_color	get_color_rgb(t_ray ray, t_data *data)
{
	t_coordinate	hit_point;
	t_color			background_color;

<<<<<<< Updated upstream
	hit_point.x = INFINITY;
	background_color = sky_color(ray);
	hit_point = get_shape_point(data, data->shapes, ray);
	if (hit_point.x == INFINITY)
=======
	background_color = sky_color(ray, data->screen.vertical.y);
	shape = hit_shape(data, ray);
	if (shape != NONE)
	{
		hit_point = get_shape_point(data, ray, shape);
		return (apply_phong_model(*data, hit_point));
	}
	else
>>>>>>> Stashed changes
		return (background_color);
	return (apply_phong_model(*data, hit_point));
}

// void	get_pixel_color(t_data *data)
// {
// 	t_ray		ray;
// 	t_color		color_rgb;
// 	t_screen	screen;
// 	int			color_hex;
// 	double		u;
// 	double		v;
// 	int			*image_pixel;

// 	image_pixel = malloc(sizeof(int) * WINDOW_HEIGHT * WINDOW_WIDTH);

// 	screen = data->screen;
// 	printf("screen.vertical = (%.2f,%.2f,%.2f)\n", screen.vertical.x,screen.vertical.y,screen.vertical.z);
// 	for (int j = WINDOW_HEIGHT - 1; j >= 0; --j)
// 	{
// 		for (int i = 0; i < WINDOW_WIDTH; ++i)
// 		{
// 			u = (double)(i) / (WINDOW_WIDTH - 1);
// 			v = (double)(j) / (WINDOW_HEIGHT - 1);
// 			ray.origin = data->camera.coordinate;
// 			ray.direction = get_ray_direction(screen.start_point,\
// 					screen.horizontal, screen.vertical, data->camera.coordinate, u, v);
// 			color_rgb = get_color_rgb(ray, data);
// 			color_hex = color_to_hex(color_rgb);
// 			printf("j = %d, y = %.2f -> color: %d\n", j, ray.direction.y, color_rgb.red);
// 			// printf("(%d,%d)-index = %d\n",i,j,j*WINDOW_HEIGHT+i);
// 			image_pixel[j * WINDOW_HEIGHT + i] = color_hex;
// 			// write_pixel_image(data, i, j, color_hex);
// 		}
// 	}
// 	for (int j = WINDOW_HEIGHT - 1; j >= 0; --j)
// 	{
// 		for (int i = 0; i < WINDOW_WIDTH; ++i)
// 		{
// 			write_pixel_image(data, i, j, image_pixel[j*WINDOW_HEIGHT+i]);
// 		}
// 	}
// 	// float k = 0.003;
// 	// applyPincushionDistortion(image_pixel, WINDOW_WIDTH, WINDOW_HEIGHT, k);
// 	// for (int j = WINDOW_HEIGHT - 1; j >= 0; --j)
// 	// {
// 	// 	for (int i = 0; i < WINDOW_WIDTH; ++i)
// 	// 	{
// 	// 		write_pixel_image(data, i, j, image_pixel[j*WINDOW_HEIGHT+i]);
// 	// 	}
// 	// }
// }


void	get_pixel_color(t_data *data)
{
	t_ray		ray;
	t_color		color_rgb;
	t_screen	screen;
	int			color_hex;
	double		u, v, r;
	double		k1 = 0.1;
	double		k2 = 0.05;
	double		distortion_factor;

	screen = data->screen;
	for (int j = WINDOW_HEIGHT - 1; j >= 0; --j)
	{
		for (int i = 0; i < WINDOW_WIDTH; ++i)
		{
			u = (double)(i) / (WINDOW_WIDTH - 1);
			v = (double)(j) / (WINDOW_HEIGHT - 1);
			
			// Compute radial distance from image center
			r = sqrt((u - 0.5) * (u - 0.5) + (v - 0.5) * (v - 0.5));
			
			// Compute distortion factor
			distortion_factor = 1 + k1 * r * r + k2 * pow(r, 4);
			
			// Apply distortion correction
			// double u_corrected = (u - 0.5) * distortion_factor + 0.5;
			// double v_corrected = (v - 0.5) * distortion_factor + 0.5;
			
			// printf("r=%.3f, factor=%.3f, u=%.3f, v=%.3f, du=%.3f,dv=%.3f\n", r, distortion_factor, u, v, u_corrected, v_corrected);
			
			ray.origin = data->camera.coordinate;
<<<<<<< Updated upstream
			ray.direction = get_ray_direction(screen.start_point,\
				screen.horizontal, screen.vertical,data->camera.coordinate, \
				u, v);
=======
			// ray.direction = get_ray_direction(screen.start_point,screen.horizontal, screen.vertical, data->camera.coordinate, u_corrected, v_corrected);
			ray.direction = vector_unit(get_ray_direction(screen.start_point,screen.horizontal, screen.vertical, data->camera.coordinate, u, v));
					
>>>>>>> Stashed changes
			color_rgb = get_color_rgb(ray, data);
			color_hex = color_to_hex(color_rgb);
			write_pixel_image(data, i, j, color_hex);
		}
	}
}
