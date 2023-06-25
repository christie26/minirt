/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:10:10 by minkim3           #+#    #+#             */
/*   Updated: 2023/06/24 21:44:12 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "model.h"

// parse_center.c
t_data			parse_center(char *filename);

// parsing_helper.c
t_cordinate		get_coordinate(char *cordinate_val);
t_color			get_color(char *color_val);
t_vector		get_vector(char *vector_val);

// parsing.c
t_ambient		get_ambient(char **tab);
t_camera		get_camera(char **tab);
t_light			get_light(char **tab);
t_sphere		get_sphere(char **tab);
t_plane			get_plane(char **tab);
t_cylinder		get_cylinder(char **tab);

//open.c
int				formatcheck_open(char *filename);

// key_press
int				key_press(int keycode, t_data *data);
int				win_close(void);
int				render(void);

#endif