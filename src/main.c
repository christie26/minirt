
#include "../includes/minirt.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*res;
	int		fd;

	if (ac != 2)
	{
		printf("Error\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		return (1);
	}
	while (1)
	{
		res = get_next_line(fd);
		if (!res)
			break ;
		printf("%s\n", res);
		free(res);
	}
	return (0);
}