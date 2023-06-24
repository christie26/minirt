/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:46:38 by minkim3           #+#    #+#             */
/*   Updated: 2023/06/24 20:38:20 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	handle_syscall(void)
{
	perror("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
	return ;
}

void	*error_msg(char *error_message)
{
	ft_putendl_fd(error_message, 2);
	return (0);
}