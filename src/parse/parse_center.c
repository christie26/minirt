
#include "../../includes/minirt.h"

static t_data	parsing(t_data data, char *line)
{
	char	**tab;

	tab = ft_split(line, ' ');
	if (!tab)
		error_msg("Error\n");
	else if (!ft_strcmp(tab[0], "A") || !ft_strcmp(tab[0], "a"))
		data.ambient = get_ambient(tab);
	else if (!ft_strcmp(tab[0], "C") || !ft_strcmp(tab[0], "c"))
		data.camera = get_camera(tab);
	else if (!ft_strcmp(tab[0], "L") || !ft_strcmp(tab[0], "l"))
		data.light = get_light(tab);
	else if (!ft_strcmp(tab[0], "pl"))
		data.plane = get_plane(tab);
	else if (!ft_strcmp(tab[0], "sp"))
		data.sphere = get_sphere(tab);
	else if (!ft_strcmp(tab[0], "cy"))
		data.cylinder = get_cylinder(tab);
	else
		error_msg(INVALID_IDENTIFIER);
	free_two_dimensional_array(tab);
	return (data);
}

t_data	parse_center(char *filename)
{
	int		fd;
	t_data	data;
	char	*line;

	fd = formatcheck_open(filename);
	ft_memset(&data, 0, 0);
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
