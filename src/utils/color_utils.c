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
