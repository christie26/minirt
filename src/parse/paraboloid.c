#include "../../includes/minirt.h"

// typedef struct s_paraboloid
// {
// 	t_coordinate	coordinate;
// 	t_vector		vector;
// 	double			diameter_x;
// 	double			diameter_y;
// 	double			height;
// 	t_color			color;
// }	t_paraboloid;

t_paraboloid	*get_paraboloid(char **tab)
{
	t_paraboloid	*paraboloid;

	paraboloid = malloc(sizeof(t_paraboloid));
	if (paraboloid == NULL)
		exit(EXIT_FAILURE);
	
	printf("tab[1] = %s\n", tab[1]);
	printf("tab[2] = %s\n", tab[2]);
	printf("tab[3] = %s\n", tab[3]);
	printf("tab[4] = %s\n", tab[4]);
	printf("tab[5] = %s\n", tab[5]);
	printf("tab[6] = %s\n", tab[6]);

	paraboloid->coordinate = get_coordinate(tab[1]);
	paraboloid->vector = get_vector(tab[2]);
	paraboloid->parameter_x = get_double(tab[3]);
	paraboloid->parameter_y = get_double(tab[4]);
	paraboloid->height = get_double(tab[5]);
	paraboloid->color = get_color(tab[6]);
	if (tab[7])
		error_msg(PARSE_PARABOLOID);
	return (paraboloid);
}
