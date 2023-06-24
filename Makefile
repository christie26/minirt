# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 20:18:20 by minkim3           #+#    #+#              #
#    Updated: 2023/06/24 21:55:36 by minkim3          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		 = ./minirt
LIBFT		 = ./libft/libft.a
DYLIB		 = ./mlx/libmlx.dylib

CC			 = cc
CFLAGS		 = -Wall -Wextra -Werror -O3 -ffast-math -g
LDFLAGS	     = -fsanitize=address

SRCDIR		 = ./src/

MAIN_PATH  	 = main/
MAIN_SRCS    = main.c
MAIN         = $(addprefix $(MAIN_PATH), $(MAIN_SRCS))

PARSING_PATH = parse/
PARSING_SRCS = open.c parse_center.c parsing_helper.c \
				ambient.c camera.c light.c plane.c \
				sphere.c cylinder.c
PARSING      = $(addprefix $(PARSING_PATH), $(PARSING_SRCS))

TOOL_PATH  	 = utils/
TOOL_SRCE	 = error.c free.c get_double.c
TOOL		 = $(addprefix $(TOOL_PATH), $(TOOL_SRCE))

SRC			 := $(addprefix $(SRCDIR), $(MAIN)) \
				$(addprefix $(SRCDIR), $(TOOL)) \
				$(addprefix $(SRCDIR), $(PARSING))
OBJ			 = ${SRC:.c=.o}

HEADER_PATH  = ./includes/
S_HEADER     = minirt.h
HEADER       = $(addprefix $(HEADER_PATH), $(S_HEADER))

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
