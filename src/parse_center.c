
#include "../include/parse.h"

int	formatcheck_open(char *filename)
{
	char	*format;
	int		fd;

	format = ft_substr(filename, ft_strlen(filename) - 3, 3);
	if (ft_memcmp(format, ".rt", 3) || ft_strlen(filename) < 4)
		error_msg(WRONG_FORMAT);
	free(format);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_syscall();
	return (fd);
}

t_identifier *set_function_pointer(void)
{
	t_identifier	*identifiers;

	identifiers = malloc(6 * sizeof(t_identifier));
	identifiers[0] = identifier_ambient;
	identifiers[1] = identifier_camera;
	identifiers[2] = identifier_light;
	identifiers[3] = identifier_plane;
	identifiers[4] = identifier_sphere;
	identifiers[5] = identifier_cylinder;
	return (identifiers);
}

void	check_identifier(t_data *data, char *line)
{
	char			**tab;
	int				index;
	t_identifier	*identifiers;
	t_identifier	operation;

	if (ft_strlen(line) == 0)
		return ;
	tab = ft_split(line, ' ');
	identifiers = set_function_pointer();
	index = -1;
	// printf("line =%s\n", line);
	if (!ft_strcmp(tab[0], "A"))
		index = AMBIENT;
	else if (!ft_strcmp(tab[0], "C"))
		index = CAMERA;
	else if (!ft_strcmp(tab[0], "L"))
		index = LIGHT;
	else if (!ft_strcmp(tab[0], "pl"))
		index = PLANE;
	else if (!ft_strcmp(tab[0], "sp"))
		index = SPHERE;
	else if (!ft_strcmp(tab[0], "cy"))
		index = CYLINDER;
	else
		error_msg(INVALID_IDENTIFIER);
	operation = identifiers[index];
	operation(data, tab);
}

t_data	*parse_center(char *filename)
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
		check_identifier(&data, line);
		free(line);
	}
	while (1);
	return (0);
}
