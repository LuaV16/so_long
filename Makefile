NAME = so_long

SRC = $(addprefix src/, main.c libft_utils.c map_errors_1.c frees.c check_valid_map.c create_map_1.c create_map_2.c game_1.c)
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
	$(CC) $(CFLAGS) -fPIE -Iincludes -IMLX42/include -o3 -c $< -o $@

$(MLX):
	cd MLX42 && cmake -B build && cmake --build build

clean:
	rm -f $(OBJ) $(GNL_OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all