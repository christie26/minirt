#include "../../includes/minirt.h"

static int	weighted_average(int color_one, int color_two, double ratio)
{
	return ((int)((1 - ratio) * (double)color_one + ratio * (double)color_two));
}

t_color	mix_color(t_color color_one, t_color color_two, double ratio)
{
	t_color	new_color;

	new_color.red = ft_min(weighted_average(color_one.red, color_two.red, \
				ratio), 255);
	new_color.green = ft_min(weighted_average(color_one.green, color_two.green, \
				ratio), 255);
	new_color.blue = ft_min(weighted_average(color_one.blue, color_two.blue, \
				ratio), 255);
	return (new_color);
}

t_color	apply_brightness(t_color color, double brightness)
{
	color.red *= brightness;
	if (color.red > 255)
		color.red = 255;
	color.green *= brightness;
	if (color.green > 255)
		color.green = 255;
	color.blue *= brightness;
	if (color.blue > 255)
		color.blue = 255;
	return (color);
}

t_color	add_color(t_color color_one, t_color color_two)
{
	t_color	color_rgb;

	color_rgb.red = ft_min(color_one.red + color_two.red, 255);
	color_rgb.green = ft_min(color_one.green + color_two.green, 255);
	color_rgb.blue = ft_min(color_one.blue + color_two.blue, 255);
	return (color_rgb);
}

t_color	multiply_color(t_color color_one, t_color color_two)
{
	t_color	color_rgb;

	color_rgb.red = color_one.red * color_two.red / 255;
	color_rgb.green = color_one.green * color_two.green / 255;
	color_rgb.blue = color_one.blue * color_two.blue / 255;
	return (color_rgb);
}
