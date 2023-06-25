/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:51:03 by minkim3           #+#    #+#             */
/*   Updated: 2023/06/24 21:47:32 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
