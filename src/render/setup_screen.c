#include "../../includes/minirt.h"

static double	degree_to_radian(double fov)
{
	double pi;

	pi = 3.14159265358979323846;
	fov = fov * pi / 180;
	return (fov);
}

t_coordinate  get_start_corner(t_coordinate origin, t_vector horizontal, \
                            t_vector vertical, double focal_length)
{
    t_coordinate    start_corner;

    start_corner.x = origin.x - horizontal.x / 2 - vertical.x / 2;
    start_corner.y = origin.y - horizontal.y / 2 - vertical.y / 2;
    start_corner.z = origin.z - horizontal.z / 2 - vertical.z / 2 - focal_length;
    return (start_corner);
}  

t_vector get_ray_direction(t_coordinate lower_left_corner, t_vector horizontal, \
                            t_vector vertical, t_coordinate origin, double u, double v)
{
    t_vector        ray_direction;
    t_coordinate    pixel;

    pixel.x = lower_left_corner.x + u * horizontal.x + v * vertical.x - origin.x;
    pixel.y = lower_left_corner.y + u * horizontal.y + v * vertical.y - origin.y;
    pixel.z = lower_left_corner.z + u * horizontal.z + v * vertical.z - origin.z;
    ray_direction = get_vector_two_point(origin, pixel);
    return (ray_direction);
}

void	setup_screen(t_data *data, int res_width, int res_height)
{
	t_vector	world_vertical;
	t_vector	horizontal;
	t_vector	vertical;

	data->screen.distance = 1;
	data->screen.window_width = res_width;
	data->screen.window_height = res_height;
	data->screen.view_width = 2 * tan(degree_to_radian(data->camera.fov));
	data->screen.view_height = data->screen.view_width * (res_height / (double)res_width);
	world_vertical = init_vector(0, 1, 0);
	horizontal = vector_unit(vector_cross(world_vertical, data->camera.vector));
	vertical = vector_unit(vector_cross(data->camera.vector, horizontal));
	data->screen.horizontal = horizontal;
	data->screen.vertical = vertical;
}











// // Transforms a vector from camera space to world space
// t_vector	transform_to_world_space(t_vector camera_vector, t_vector camera_orientation)
// {
// 	// Implementation depends on how you define your camera's orientation.
// 	// If your camera's orientation is a unit vector pointing in the direction the camera is looking, you might need to rotate camera_vector by the same amount.
// }

// // Returns a ray from the camera to a point on the virtual screen
// t_vector	get_ray_to_screen(t_camera camera, t_screen screen, int pixel_x, int pixel_y)
// {
// 	// Calculate the position of the point on the screen corresponding to the pixel
// 	// This will depend on the resolution and size of your screen
// 	// Then subtract the camera's position from this point to get the ray
// }

// // Returns the point of intersection of a ray with a shape, or a special value if there is no intersection
// t_coordinate	get_intersection_sphere(t_vector ray, t_sphere sphere)
// {
// 	// Implementation depends on the shape
// 	// For a sphere, you can use the quadratic formula
// 	// For a plane, you can use the dot product
// 	// For a cylinder, you can use the quadratic formula and the dot product
// }

// t_coordinate	get_intersection_plane(t_vector ray, t_plane plane)
// {
// }	

// t_coordinate	get_intersection_cylinder(t_vector ray, t_cylinder cylinder)
// {
// }
