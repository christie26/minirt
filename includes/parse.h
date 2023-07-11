/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:48:24 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:48:24 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "model.h"

// parse_center.c
t_data			parse_center(char *filename);

// parsing_helper.c
t_coordinate	get_coordinate(char *coordinate_val);
t_color			get_color(char *color_val);
t_vector		get_vector(char *vector_val);

t_coordinate	get_coordinate_double(double x, double y, double z);

// parsing.c
t_ambient		get_ambient(char **tab, char *bit_mask);
t_camera		get_camera(char **tab, char *bit_mask);
t_light			*get_light(char **tab);
t_sphere		*get_sphere(char **tab);
t_plane			*get_plane(char **tab);
t_cylinder		*get_cylinder(char **tab);
t_paraboloid	*get_paraboloid(char **tab);

//open.c
int				formatcheck_open(char *filename);

#endif