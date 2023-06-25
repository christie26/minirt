#include "../../includes/minirt.h"

void	write_pixel_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	// if (x > 950 || x < 50 || y > 950 | y < 50)
		// return ;
    // printf("data->addr = %p, color = %d\n", data->addr, color);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    // printf("dst = %p\n", dst);
	*(unsigned int *)dst = color;
	return ;
}

void first_ppm(t_data *data)
{

    // Image
    const int image_width = 1920;
    const int image_height = 1080;

    // Render

    for (int j = image_height-1; j >= 0; --j) 
	{
        for (int i = 0; i < image_width; ++i) 
		{
            double r = (double)(i) / (image_width-1);
            double g = (double)(j) / (image_height-1);
            double b = 0.25;


            int ir = (int)(255.999 * r);
            int ig = (int)(255.999 * g);
            int ib = (int)(255.999 * b);


            // rgb to color 
            int color = rgb_to_hex(ir, ig, ib);
            
            write_pixel_image(data, i, j, color);
        }
    }
}