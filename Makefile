NAME = so_long

SRC = $(addprefix src/, main.c)
GNL_SRC = $(addprefix gnl/, get_next_line.c get_next_line_utils.c)

OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ)
	$(CC) $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all