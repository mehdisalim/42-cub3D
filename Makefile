# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalim <esalim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 11:42:51 by esalim            #+#    #+#              #
#    Updated: 2023/09/26 20:54:22 by esalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

NAMEB	=	cub3D_bonus

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -O3

SRC_BONUS	=	bonus/src/parsing_map/main_parsing.c \
				bonus/src/parsing_map/parsing_utils.c \
				bonus/src/parsing_map/checking_map.c \
				bonus/src/parsing_map/read_map.c \
				bonus/src/parsing_map/parsing_map.c \
				bonus/src/images/image.c \
				bonus/src/images/draw_player.c \
				bonus/src/images/press_key.c \
				bonus/src/images/init_struct.c \
				bonus/src/images/key_hook.c \
				bonus/src/raycasting/find_distance.c \
				bonus/src/raycasting/dda.c \
				bonus/src/images/draw.c \
				bonus/src/images/drawDynamicMap.c \
				bonus/src/game/display_3D.c \
				bonus/src/utils/imageHandler.c \
				bonus/src/utils/convertor.c \
				bonus/src/utils/destroy.c \
				bonus/src/utils/imageChecker.c \
				bonus/src/main.c 

SRC			=	mandatory/src/parsing_map/main_parsing.c \
				mandatory/src/parsing_map/parsing_utils.c \
				mandatory/src/parsing_map/checking_map.c \
				mandatory/src/parsing_map/read_map.c \
				mandatory/src/parsing_map/parsing_map.c \
				mandatory/src/images/image.c \
				mandatory/src/images/press_key.c \
				mandatory/src/images/init_struct.c \
				mandatory/src/images/key_hook.c \
				mandatory/src/raycasting/find_distance.c \
				mandatory/src/raycasting/dda.c \
				mandatory/src/images/draw.c \
				mandatory/src/game/display_3D.c \
				mandatory/src/utils/imageHandler.c \
				mandatory/src/utils/convertor.c \
				mandatory/src/utils/destroy.c \
				mandatory/src/utils/imageChecker.c \
				mandatory/src/main.c 

OBJS		=	$(SRC:.c=.o)
OBJS_BONUS	=	$(SRC_BONUS:.c=.o)

MLX42 = mlx/build/libmlx42.a

GLFW = $(shell brew --prefix glfw)

framework = -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"$(GLFW)/lib" $(MLX42)

all		:	$(NAME)

bonus	:	$(NAMEB)

$(NAMEB)	:	$(OBJS_BONUS)
	make -C libft
	$(CC) $(CFLAGS) libft/libft.a $^ -o $(NAMEB) $(framework)

$(NAME)	:	$(OBJS)
	make -C libft
	$(CC) $(CFLAGS) libft/libft.a $^ -o $@ $(framework)

%.o		:	%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean	:
	make -C libft clean 
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean	:	clean
	make -C libft fclean
	rm -rf $(NAME) $(NAMEB)

re		:	fclean	all	