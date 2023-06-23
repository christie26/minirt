
#ifndef PARSE_H
# define PARSE_H

# include "model.h"
# include "error.h"

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

# include "../include/model.h"
# include "../include/error.h"
# include "../libft/libft.h"

// key_press
int		key_press(int keycode, t_data *data);
int		win_close(void);
int		render(void);

// error
void	*handle_syscall(char *error_message);
void	*error_msg(char *error_message);

#endif