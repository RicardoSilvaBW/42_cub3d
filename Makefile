#CONFIG
CC = cc
CFLAGS = -Werror -Wall -Wextra -g
INCLUDES = -I includes -I libs -I libs/minilibx
RM = rm -f
NAME = cub3D
BONUS_NAME = cub3D_bonus

#MANDATORY
SRC_DIR = src
SRC_BONUS_DIR = src_bonus
INIT_DIR = $(SRC_DIR)/initialization
PARSE_DIR = $(SRC_DIR)/parser
UTILS_DIR = $(SRC_DIR)/utils
RENDER_DIR = $(SRC_DIR)/render

#BONUS
BONUS_DIR = $(SRC_BONUS_DIR)/bonus
INIT_BONUS_DIR = $(SRC_BONUS_DIR)/initialization
PARSE_BONUS_DIR = $(SRC_BONUS_DIR)/parser
UTILS_BONUS_DIR = $(SRC_BONUS_DIR)/utils
RENDER_BONUS_DIR = $(SRC_BONUS_DIR)/render

#LIBS
LIBFT_DIR = libs/libft
MLX_DIR = libs/minilibx

#MANDATORY 
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

SRC_BONUS_FILES = \
	$(SRC_BONUS_DIR)/main_bonus.c \
	$(INIT_BONUS_DIR)/init_bonus.c \
	$(INIT_BONUS_DIR)/input_bonus.c \
	$(UTILS_BONUS_DIR)/clean_bonus.c \
	$(UTILS_BONUS_DIR)/drawing_utils_bonus.c \
	$(PARSE_BONUS_DIR)/check_args_bonus.c \
	$(PARSE_BONUS_DIR)/check_textures_bonus.c \
	$(PARSE_BONUS_DIR)/check_colors_bonus.c \
	$(PARSE_BONUS_DIR)/check_map_bonus.c \
	$(PARSE_BONUS_DIR)/check_map_utils_bonus.c \
	$(PARSE_BONUS_DIR)/set_map_bonus.c \
	$(PARSE_BONUS_DIR)/parser_bonus.c \
	$(RENDER_BONUS_DIR)/render_raycasting_bonus.c \
	$(RENDER_BONUS_DIR)/render_textures_bonus.c \
	$(RENDER_BONUS_DIR)/render_calculate_bonus.c \

OBJS = $(SRC_FILES:%.c=%.o)
BONUS_OBJS = $(SRC_BONUS_FILES:%.c=%.o)
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -L/usr/X11/lib -lXext -lX11 -lm -lz

all: $(LIBFT) $(MLX) $(NAME)

bonus: $(LIBFT) $(MLX) $(BONUS_NAME)

$(LIBFT):
	make -s -C $(LIBFT_DIR)

$(MLX):
	make -s -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS*) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -s -C $(LIBFT_DIR) clean
	make -s -C $(MLX_DIR) clean
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	make -s -C $(LIBFT_DIR) fclean
	make -s -C $(MLX_DIR) fclean

re: clean all

.PHONY: all clean fclean re
