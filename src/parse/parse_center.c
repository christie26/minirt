
#include "../../includes/minirt.h"

static void	add_shape(t_list *shapes, char **tab, int type)
{
	void	*new_shape;

	if (type == SPHERE)
		new_shape = get_sphere(tab);
	else if (type == PLANE)
		new_shape = get_plane(tab);
	else
		new_shape = get_cylinder(tab);
	add_node(&shapes, new_shape, type);
}

static t_list	*parse_shape(char **tab)
{
	t_list *shapes;

	shapes = ft_calloc(sizeof(t_list), 1);
	if (!ft_strcmp(tab[0], "pl"))
		add_shape(shapes, tab, PLANE);
	else if (!ft_strcmp(tab[0], "sp"))
		add_shape(shapes, tab, SPHERE);
	else if (!ft_strcmp(tab[0], "cy"))
		add_shape(shapes, tab, CYLINDER);
	else
	{
		error_msg("Error\n");
	}
	return (shapes);
}

static t_data	parsing(t_data data, char *line)
{
	char	**tab;

	if (!line || line[0] == '#' || line[0] == '\n')
		return (data);
	tab = ft_split(line, ' ');
	if (!tab)
		error_msg("Error\n");
	else if (!ft_strcmp(tab[0], "A") || !ft_strcmp(tab[0], "a"))
		data.ambient = get_ambient(tab);
	else if (!ft_strcmp(tab[0], "C") || !ft_strcmp(tab[0], "c"))
		data.camera = get_camera(tab);
	else if (!ft_strcmp(tab[0], "L") || !ft_strcmp(tab[0], "l"))
		data.light = get_light(tab);
	else
	{
		data.shapes = parse_shape(tab);
	}
	free_two_dimensional_array(tab);
	return (data);
}

t_data	parse_center(char *filename)
{
	int		fd;
	t_data	data;
	char	*line;

	fd = formatcheck_open(filename);
	ft_memset(&data, 0, sizeof(t_data));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data = parsing(data, line);
		free(line);
	}
	return (data);
}
