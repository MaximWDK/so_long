SRCS = 	src/main.c \
		src/initialize.c \
		src/map.c \
		src/moves.c \
		src/set_images.c \
		src/utils.c \
		src/check.c \
		src/exit.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_printf_utils.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

SRCSB =	src_bonus/main_bonus.c \
		src_bonus/initialize_bonus.c \
		src_bonus/map_bonus.c \
		src_bonus/moves_bonus.c \
		src_bonus/set_images_bonus.c \
		src_bonus/utils_bonus.c \
		src_bonus/check_bonus.c \
		src_bonus/exit_bonus.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_printf_utils.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

NAME = so_long
NAME_BONUS = so_long_bonus
OBJ = ${SRCS:.c=.o}
OBJB = ${SRCSB:.c=.o}
LIBFTDIR = libft
LIBFT = ${LIBFTDIR}/libft.a
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		make -C $(LIBFTDIR)
		$(CC) $(OBJ) $(CFLAGS) ${LIBFT} -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_BONUS): $(OBJB)
		make -C $(LIBFTDIR)
		$(CC) $(OBJB) $(CFLAGS) ${LIBFT} -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

all: ${NAME}

bonus: ${NAME_BONUS}

clean:
		make clean -C $(LIBFTDIR)
		${RM} ${OBJ} ${OBJB}

fclean: clean
		make fclean -C $(LIBFTDIR)
		${RM} ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re bonus