#include "../../includes/minirt.h"

static void	add_object(t_list *objects, char **tab, int type)
{
	void	*new_object;

	if (type == SPHERE)
		new_object = get_sphere(tab);
	else if (type == PLANE)
		new_object = get_plane(tab);
	else
		new_object = get_cylinder(tab);
	add_node(&objects, new_object, type);
}

static void	parse_object(t_list **objects, char **tab)
{
	if (!ft_strcmp(tab[0], "pl"))
		add_object(*objects, tab, PLANE);
	else if (!ft_strcmp(tab[0], "sp"))
		add_object(*objects, tab, SPHERE);
	else if (!ft_strcmp(tab[0], "cy"))
		add_object(*objects, tab, CYLINDER);
	else
	{
		printf("tab[0]: %s\n", tab[0]);
		error_msg(INVALID_IDENTIFIER);
	}
}

static void	parse_line(t_data *data, char *line, char *bit_mask)
{
	char	**tab;

	if (!line || line[0] == '#' || line[0] == '\n')
		return ;
	tab = ft_split(line, ' ');
	if (!tab)
		error_msg(MALLOC_ERROR);
	if (!ft_strcmp(tab[0], "A"))
		data->ambient = get_ambient(tab, bit_mask);
	else if (!ft_strcmp(tab[0], "C"))
		data->camera = get_camera(tab, bit_mask);
	else if (!ft_strcmp(tab[0], "L"))
		data->light = get_light(tab, bit_mask);
	else
		parse_object(&data->object_list, tab);
	free_two_dimensional_array(tab);
	return ;
}

t_data	parse_center(char *filename)
{
	t_data	data;
	int		fd;
	char	*line;
	char	bit_mask;

	fd = formatcheck_open(filename);
	ft_memset(&data, 0, sizeof(t_data));
	data.object_list = create_linkedlist();
	bit_mask = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parse_line(&data, line, &bit_mask);
		free(line);
	}
	return (data);
}
