
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
	{
		handle_syscall();
		exit(EXIT_FAILURE);
	}
	return (fd);
}


// check_identifier

t_data	*parse_center(char *filename)
{
	int		fd;
	char	*line;
 
	fd = formatcheck_open(filename);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		// check_identifier(line);
		printf("%s\n", line);
		free(line);
	}
	return (0);
}