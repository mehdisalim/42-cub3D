# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 11:42:51 by esalim            #+#    #+#              #
#    Updated: 2023/08/23 19:15:01 by esekouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g

# SRC		=	src/parsing_map/main.c

SRC		=	src/images/image.c

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