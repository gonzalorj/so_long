NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX = mlx/Makefile.gen
LIBFT = libft/libft.a
INC = -I ./includes -I ./libft -I ./mlx
LIB	= -L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
OBJ	= $(patsubst src%, obj%, $(SRC:.c=.o))
SRC = src/cleaner.c \
		src/game.c \
		src/listener.c \
		src/main.c \
		src/map_utils.c \
		src/map_utils2.c \
		src/renders.c 
NRM_DIR = ./src ./includes ./libft

all: $(MLX) $(LIBFT) obj $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)

$(MLX):
		@echo "Compiling mlx.."
		@make -s -C mlx
		@echo "Minilibx ready!"

$(LIBFT):		
		@echo "Compiling libft.."
		@make -s -C libft
		@echo "Libft ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "All clean!"

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "Exe clean!"

re:			fclean all

norm:
			norminette $(NRM_DIR)

.PHONY:		all clean fclean re


