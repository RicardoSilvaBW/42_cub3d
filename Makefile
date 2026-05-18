CC = cc
CFLAGS = -Werror -Wall -Wextra -g
INCLUDES = -I includes -I libs -I libs/minilibx
RM = rm -f 
NAME = cub3d

SRC_DIR = src
PARSE_DIR = $(SRC_DIR)/parser
LIBFT_DIR = libs/libft
MLX_DIR = libs/minilibx

SRC_FILES = \
	$(SRC_DIR)/main.c \
	$(PARSE_DIR)/check_args.c \

OBJS = $(SRC_FILES:%.c=%.o)
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -L/usr/X11/lib -lXext -lX11 -lm -lz

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	make -s -C $(LIBFT_DIR)

$(MLX):
	make -s -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -s -C $(LIBFT_DIR) clean
	make -s -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make -s -C $(LIBFT_DIR) fclean
	make -s -C $(MLX_DIR) fclean

re: clean all

.PHONY: all clean fclean re 
	

