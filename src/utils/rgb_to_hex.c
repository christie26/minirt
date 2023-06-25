#include "../../includes/minirt.h"

int rgb_to_hex(int r, int g, int b)
{
	int color;

	color = 256 * r + 16 * g + b;
	return (color);
}