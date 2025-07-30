NAME = so_long

SRC = $(addprefix src/, main.c libft_utils.c errors.c frees.c check_map.c map.c)
GNL_SRC = $(addprefix gnl/, get_next_line.c get_next_line_utils.c)

OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX = MLX42/build/libmlx42.a

all: $(MLX) $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ)
	$(CC) $(CFLAGS) -fPIE $^ -LMLX42/build -lmlx42 -ldl -lglfw -lm -lX11 -lpthread -pie -o $@

%.o: %.c
	$(CC) $(CFLAGS) -fPIE -Iincludes -IMLX42/include -O3 -c $< -o $@

$(MLX):
	cd MLX42 && cmake -B build && cmake --build build

clean:
	rm -f $(OBJ) $(GNL_OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all