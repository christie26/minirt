#include "../../includes/minirt.h"

t_color mix_color(t_color color_one, t_color color_two, double ratio)
{
    t_color new_color;

    new_color.red = get_smaller_value((int)((1 - ratio) * (double)color_one.red + ratio * (double)color_two.red), 255);
    new_color.green = get_smaller_value((int)((1 - ratio) * (double)color_one.green + ratio * (double)color_two.green), 255);
    new_color.blue = get_smaller_value((int)((1 - ratio) * (double)color_one.blue + ratio * (double)color_two.blue), 255);
    return (new_color);
}

t_color	apply_brightness(t_color color, double brightness)
{
	color.red *= brightness;
	color.green *= brightness;
	color.blue *= brightness;
	return (color);
}

t_color	add_color(t_color color_one, t_color color_two)
{
	t_color	color_rgb;

	color_rgb.red = get_smaller_value(color_one.red + color_two.red, 255);
	color_rgb.green = get_smaller_value(color_one.green + color_two.green, 255);
	color_rgb.blue = get_smaller_value(color_one.blue + color_two.blue, 255);
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
