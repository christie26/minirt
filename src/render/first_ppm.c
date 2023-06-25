#include "../../includes/minirt.h"

void	write_pixel_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 950 || x < 50 || y > 950 | y < 50)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return ;
}

void first_ppm(t_data *data)
{

    // Image

    const int image_width = 256;
    const int image_height = 256;

    // Render

    // std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

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

			printf("(%d, %d) = R: %d, G: %d, B: %d\n", i, j, ir, ig, ib);
            // std::cout << ir << ' ' << ig << ' ' << ib << '\n';

            // rgb to color 
            int color = rgb_to_hex(ir, ig, ib);
            
            write_pixel_image(data, i, j, color);
        }
    }
}