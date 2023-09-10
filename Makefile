# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 11:42:51 by esalim            #+#    #+#              #
#    Updated: 2023/09/07 13:00:50 by esekouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address

SRC		=	src/parsing_map/main_parsing.c \
			src/parsing_map/parsing_utils.c \
			src/parsing_map/checking_map.c \
			src/parsing_map/read_map.c \
			src/parsing_map/parsing_map.c \
			src/images/image.c \
			src/images/key_hook.c \
			src/images/find_distance.c \
			src/images/draw.c \
			src/images/dda.c \
			# src/main.c 

OBJS	=	$(SRC:.c=.o)

MLX42 = mlx/build/libmlx42.a

GLFW = $(shell brew --prefix glfw)

framework = -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"$(GLFW)/lib" $(MLX42)
# framework = -framework Cocoa -framework OpenGL -framework IOKit


all		:	$(NAME)

$(NAME)	:	$(OBJS)
	make -C libft
	$(CC) $(CFLAGS)  libft/libft.a $^ -o $@ $(framework)
	
%.o		:	%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean	:
	make -C libft clean 
	rm -rf $(OBJS)

fclean	:	clean
	make -C libft fclean
	rm -rf $(NAME)

re		:	fclean	all	


run		:
	./$(NAME) maps/map1.cub