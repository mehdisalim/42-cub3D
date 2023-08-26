# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalim <esalim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 11:42:51 by esalim            #+#    #+#              #
#    Updated: 2023/08/26 13:51:56 by esalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g

SRC		=	src/parsing_map/main.c src/parsing_map/parsing_map.c

OBJS	=	$(SRC:.c=.o)

LIBFT	=	libft

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	make -C libft
	$(CC) $(CFLAGS)  libft/libft.a $^ -o $@
	
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