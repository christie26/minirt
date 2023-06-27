#include "../../includes/minirt.h"

// color = 256 * r + 16 * g + b;
int rgb_to_hex(int r, int g, int b)
{
	int color;

	color = (r << 16) | (g << 8) | b;
	return (color);
}

// color = 256 * r + 16 * g + b;
int color_to_hex(t_color color)
{
	int color_hex;

	color_hex = (color.red << 16) | (color.green << 8) | color.blue;
	return (color_hex);
}

t_color gredient_color(t_color color_one, t_color color_two, double ratio)
{
    t_color new_color;

    new_color.red = (int)((1 - ratio) * (double)color_one.red + ratio * (double)color_two.red);
    new_color.green = (int)((1 - ratio) * (double)color_one.green + ratio * (double)color_two.green);
    new_color.blue = (int)((1 - ratio) * (double)color_one.blue + ratio * (double)color_two.blue);
    return (new_color);
}