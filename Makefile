# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsolet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 03:17:57 by hsolet            #+#    #+#              #
#    Updated: 2024/04/13 13:39:56 by hsolet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
INCLUDES = -I/usr/include -Imlx
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
SRC = affichage.c check_map.c error.c move.c so_long.c

OBJ = $(SRC:.c=.o)

SOLONG = so_long

all : libft solong

libft : 
	@make -s -C libft

solong :  $(OBJ)
	@$(CC) $(CFLAGS) -o $(SOLONG) $(OBJ) libft/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean: 
	@rm -f *.o
	@make clean -C libft


fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@make fclean -C libft

re: fclean all
	@echo "clean ☑️"
	@echo "compil ☑️"

.PHONY: clean fclean re all libft
