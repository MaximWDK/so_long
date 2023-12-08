SRCS =  main.c \
		initialize.c \
		map.c \
		moves.c \
		set_images.c \
		utils.c \
		check.c \
		exit.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_printf_utils.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

NAME = so_long
OBJ = ${SRCS:.c=.o}
LIBFTDIR = libft
LIBFT = ${LIBFTDIR}/libft.a
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		make -C $(LIBFTDIR)
		$(CC) $(OBJ) $(CFLAGS) ${LIBFT} minilibx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

all: ${NAME}

clean:
		make clean -C $(LIBFTDIR)
		${RM} ${OBJ}

fclean: clean
		make fclean -C $(LIBFTDIR)
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re