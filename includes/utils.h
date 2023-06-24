/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:48:25 by minkim3           #+#    #+#             */
/*   Updated: 2023/06/24 21:27:23 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// error.c
void	ft_putendl_fd(char *s, int fd);
void	*error_msg(char *error_message);
void	handle_syscall(void);

// parse_utils.c
double	string_to_double(char *str);
void	string_to_color(char *str, t_color *color);

//free.c
void	free_two_dimensional_array(char **array);

// get double.c
double	get_double(const char *str);

#endif
