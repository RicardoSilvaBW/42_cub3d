CC = cc
CFLAGS = -Werror -Wall -Wextra -g
INCLUDES = -I includes -I libs -I libs/minilibx
RM = rm -f
NAME = cub3D

SRC_DIR = src
INIT_DIR = $(SRC_DIR)/initialization
PARSE_DIR = $(SRC_DIR)/parser
UTILS_DIR = $(SRC_DIR)/utils
RENDER_DIR = $(SRC_DIR)/render
LIBFT_DIR = libs/libft
MLX_DIR = libs/minilibx

SRC_FILES = \
	$(SRC_DIR)/main.c \
	$(INIT_DIR)/init.c \
	$(INIT_DIR)/input.c \
	$(UTILS_DIR)/clean.c \
	$(UTILS_DIR)/drawing_utils.c \
	$(PARSE_DIR)/check_args.c \
	$(PARSE_DIR)/check_textures.c \
	$(PARSE_DIR)/check_colors.c \
	$(PARSE_DIR)/check_map.c \
	$(PARSE_DIR)/check_map_utils.c \
	$(PARSE_DIR)/set_map.c \
	$(PARSE_DIR)/parser.c \
	$(RENDER_DIR)/render_raycasting.c \
	$(RENDER_DIR)/render_textures.c \
	$(RENDER_DIR)/render_calculate.c \

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
