NAME        := so_long
CC        := cc
FLAGS    := -Wall -Wextra -Werror -g
SRCS        :=      libft/ft_isdigit.c \
                          libft/ft_strchr.c \
                          libft/ft_memchr.c \
                          libft/ft_isalnum.c \
                          libft/ft_strtrim.c \
                          libft/ft_striteri.c \
                          libft/get_next_line.c \
                          libft/ft_putnbr_fd.c \
                          libft/ft_calloc.c \
                          libft/ft_strmapi.c \
                          libft/ft_substr.c \
                          libft/ft_isprint.c \
                          libft/ft_strdup.c \
                          libft/ft_itoa.c \
                          libft/ft_memcpy.c \
                          libft/ft_strnstr.c \
                          libft/ft_tolower.c \
                          libft/ft_isalpha.c \
                          libft/ft_strlcpy.c \
                          libft/ft_putendl_fd.c \
                          libft/ft_printf/ft_str_len.c \
                          libft/ft_printf/ft_putstr.c \
                          libft/ft_printf/ft_count_hexa.c \
                          libft/ft_printf/ft_count_nbr.c \
                          libft/ft_printf/ft_void_hexa.c \
                          libft/ft_printf/ft_putnbr_base.c \
                          libft/ft_printf/ft_printf.c \
                          libft/ft_printf/ft_putnbr.c \
                          libft/ft_printf/ft_putchar.c \
                          libft/ft_strlen.c \
                          libft/ft_atoi.c \
                          libft/ft_memset.c \
                          libft/ft_memcmp.c \
                          libft/ft_putstr_fd.c \
                          libft/ft_isascii.c \
                          libft/ft_strjoin.c \
                          libft/ft_strncmp.c \
                          libft/ft_putchar_fd.c \
                          libft/ft_strrchr.c \
                          libft/ft_split.c \
                          libft/ft_memmove.c \
                          libft/ft_bzero.c \
                          libft/ft_strlcat.c \
                          libft/ft_toupper.c \
                          error.c \
                          check_map.c \
                          affichage.c \
                          move.c \
                          so_long.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

RM		    := rm -f



$(NAME): ${OBJS}
			@echo "Linux compilation of $(NAME) ..."
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			@ $(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			@echo "$(NAME) created[0m ✔️"


all:		${NAME}




clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "Deleting $(NAME) objs ✔️"




fclean:		clean
			@ ${RM} ${NAME}
			@ $(MAKE) -C mlx_linux clean 
			@ echo "Deleting $(NAME) binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


