
#include "../include/parse.h"

void	identifier_ambient(t_data *data, char **tab)
{

	data->ambient.ratio = string_to_double(tab[1]);
	string_to_color(tab[2], &data->ambient.color);

	// printf("I will parse ambient light with this line\n%s\n", line);
	(void)(data);
	return ;
}

void	identifier_camera(t_data *data, char **tab)
{
	// printf("I will parse camera with this line\n%s\n", line);
	(void)(data);
	(void)(tab);
	return ;
}

void	identifier_light(t_data *data, char **tab)
{
	// printf("I will parse light with this line\n%s\n", line);
	(void)(data);
	(void)(tab);
	return ;
}

void	identifier_plane(t_data *data, char **tab)
{
	// printf("I will parse plane with this line\n%s\n", line);
	(void)(data);
	(void)(tab);
	return ;
}

void	identifier_sphere(t_data *data, char **tab)
{
	// printf("I will parse sphere with this line\n%s\n", line);
	(void)(data);
	(void)(tab);
	return ;
}

void	identifier_cylinder(t_data *data, char **tab)
{
	// printf("I will parse cylinder with this line\n%s\n", line);
	(void)(data);
	(void)(tab);
	return ;
}
 