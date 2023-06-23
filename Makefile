
SRC			= main.c

SRCDIR		= ./src

SRC			:= $(addprefix $(SRCDIR)/, $(SRC))
OBJ			= ${SRC:.c=.o}

HEADER_PATH     = ./includes/
S_HEADER        = model.h header.h minirt.h
HEADER          = $(addprefix $(HEADER_PATH), $(S_HEADER))

NAME		= ./minirt
LIBFT		= ./libft/libft.a
DYLIB		= ./mlx/libmlx.dylib

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O3 -ffast-math -g
LDFLAGS		= -fsanitize=address

all:		${NAME}

%.o: 		%.c $(DYLIB) $(HEADER)
			$(CC) $(CFLAGS) -Imlx -Ilibft -c $< -o $@

$(NAME): 	$(OBJ) $(DYLIB) $(LIBFT)
			$(CC) $(OBJ) -L./mlx -lmlx -L./libft -lft -framework OpenGL -framework AppKit -o $(NAME) 

$(LIBFT):
			@make -j3 -C ./libft all
$(DYLIB):	
			@make -C ./mlx
			cp $(DYLIB) ./

clean:
			${RM} ${OBJ}
			@make -C ./libft clean
			@make -C ./mlx clean

fclean:		clean
			${RM} ${NAME}
			@make -C ./libft fclean

re:			fclean all

.PHONY:		all clean fclean re
