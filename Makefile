NAME		 = ./minirt
LIBFT		 = ./libft/libft.a
DYLIB		 = ./mlx/libmlx.dylib

CC			 = cc
CFLAGS		 = -Wall -Wextra -Werror -O3 -ffast-math -g
LDFLAGS	     = -fsanitize=address

SRCDIR		 = ./src/

MAIN_PATH 	 = main/
MAIN_SRCS 	 = main.c
MAIN       	 = $(addprefix $(MAIN_PATH), $(MAIN_SRCS))

PARSING_PATH = parse/
PARSING_SRCS = open.c parse_center.c parsing_helper.c \
				ambient.c camera.c light.c plane.c \
				sphere.c cylinder.c paraboloid.c
				
PARSING      = $(addprefix $(PARSING_PATH), $(PARSING_SRCS))

RENDER_PATH  = render/
RENDER_SRCS  = render.c key_press.c setup_screen.c \
				get_closest_object.c phong_model.c \
				get_hit_point.c point_sphere.c point_plane.c point_cylinder.c point_paraboloid.c \
				checker_sphere.c checker_plane.c checker_cylinder.c \
				shadow_center.c specular.c threads.c \
				blocked_object.c
				
RENDER       = $(addprefix $(RENDER_PATH), $(RENDER_SRCS))

VECTOR_PATH  = vector/
VECTOR_SRCE	 = init_vector.c basic_calculations.c advanced_calculations.c other_vector.c
VECTOR		 = $(addprefix $(VECTOR_PATH), $(VECTOR_SRCE))

TOOL_PATH  	 = utils/
TOOL_SRCE	 = error.c free.c get_double.c color_utils.c \
				mlx_utils.c math_utils.c change_color.c linked_list.c \
				coordinate.c screen_utils.c light_utils.c ray_utils.c \
				get_normal.c paraboloid_utils.c
TOOL		 = $(addprefix $(TOOL_PATH), $(TOOL_SRCE))

SRC			 := $(addprefix $(SRCDIR), $(MAIN)) \
				$(addprefix $(SRCDIR), $(TOOL)) \
				$(addprefix $(SRCDIR), $(PARSING)) \
				$(addprefix $(SRCDIR), $(RENDER)) \
				$(addprefix $(SRCDIR), $(VECTOR))
OBJ			 = ${SRC:.c=.o}

HEADER_PATH  = ./includes/
S_HEADER     = minirt.h
HEADER       = $(addprefix $(HEADER_PATH), $(S_HEADER))

all:		${NAME}

%.o: 		%.c $(DYLIB) $(HEADER)
			$(CC) $(CFLAGS) -Imlx -Ilibft -c $< -o $@
			# $(CC) $(CFLAGS) $(LDFLAGS) -Imlx -Ilibft -c $< -o $@

$(NAME): 	$(OBJ) $(DYLIB) $(LIBFT)
			$(CC) $(OBJ) -L./mlx -lmlx -L./libft -lft -framework OpenGL -framework AppKit -o $(NAME) 
			# $(CC) $(OBJ) $(LDFLAGS) -L./mlx -lmlx -L./libft -lft -framework OpenGL -framework AppKit -o $(NAME) 

$(LIBFT):
			@make -j3 -C ./libft all
$(DYLIB):	
			@make -C ./mlx
			cp $(DYLIB) ./

clean:
			${RM} ${OBJ}
			@make -C ./libft clean
			# @make -C ./mlx clean

fclean:		clean
			${RM} ${NAME}
			@make -C ./libft fclean

re:			fclean all

.PHONY:		all clean fclean re
