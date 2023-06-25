
#include "../../includes/minirt.h"

static int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_syscall();
	return (fd);
}

int	formatcheck_open(char *filename)
{
	char	*format;
	int		fd;

	format = ft_substr(filename, ft_strlen(filename) - 3, 3);
	if (ft_memcmp(format, ".rt", 3) || ft_strlen(filename) < 4)
		error_msg(WRONG_FORMAT);
	free(format);
	fd = open_file(filename);
	return (fd);
}
