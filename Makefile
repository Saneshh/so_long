NAME        := so_long
CC        := cc
CFLAGS    := -Wall -Wextra -Werror -g
SRCS        :=            error.c \
                          check_map.c \
                          affichage.c \
                          move.c \
                          so_long.c \
			  parsing.c\
                          
OBJS        := $(SRCS:.c=.o)

LIB_DIR = libft
LIB_A = $(LIB_DIR)/libft.a
LIB_FLAGS = -L$(LIB_DIR) -lft

MLX_DIR = mlx_linux
MLX_A = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -I $(MLX_DIR) -L$(MLX_DIR) -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

RM		    := rm -f



$(NAME): $(LIB_A) $(MLX_A) ${OBJS}
			@echo "Linux compilation of $(NAME) ..."
			@ $(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS) $(LIB_FLAGS) $(MLX_FLAGS)
			@echo "$(NAME) created[0m ✔️"


all:		${NAME}


$(LIB_A):
	make -C $(LIB_DIR)

$(MLX_A):
	make -C $(MLX_DIR)


clean:
			@ ${RM} $(OBJS)
			@ make -C $(LIB_DIR) clean
			@ make -C $(MLX_DIR) clean
			@ echo "Deleting $(NAME) objs ✔️"




fclean:		clean
			@ ${RM} ${NAME}
			@ make -C $(LIB_DIR) fclean
			@ echo "Deleting $(NAME) binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


