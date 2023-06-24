#ifndef PARSE_H
# define PARSE_H

# include "model.h"
# include "error.h"

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "../include/model.h"
# include "../include/error.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef void	(*t_identifier)(t_data*, char**);

typedef enum e_iden
{
	AMBIENT,
	CAMERA,
	LIGHT,
	PLANE,
	SPHERE,
	CYLINDER
}	t_iden;

// parse
t_data	*parse_center(char *filename);

// identifier
void	identifier_ambient(t_data *data, char **tab);
void	identifier_camera(t_data *data, char **tab);
void	identifier_light(t_data *data, char **tab);
void	identifier_plane(t_data *data, char **tab);
void	identifier_sphere(t_data *data, char **tab);
void	identifier_cylinder(t_data *data, char **tab);

// parse_utils
double	string_to_double(char *str);
void	string_to_color(char *str, t_color *color);

// key_press
int		key_press(int keycode, t_data *data);
int		win_close(void);
int		render(void);

// error
void	handle_syscall(void);
void	error_msg(char *error_message);

#endif