/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:26:07 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/05/22 14:09:41 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
#include "mlx.h"
#include "minilibx/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>

//ENUM

typedef enum e_identifier
{
  ID_NONE,
  ID_NO,
  ID_SO,
  ID_WE,
  ID_EA,
  ID_F,
  ID_C
} t_identifier;

enum e_keys
{
	key_w = 1u,
	key_a = 1u << 1,
	key_s = 1u << 2,
	key_d = 1u << 3,
	key_up = 1u << 4,
	key_down = 1u << 5,
	key_left = 1u << 6,
	key_right = 1u << 7
};

//STRUCTS

typedef struct s_textures
{
  char          *north;
  char          *south;
  char          *west;
  char          *east;
  int           floor[3];
  int           ceiling[3];
  int           floor_set;
  int           ceiling_set;
  unsigned long hex_floor_color;
  unsigned long hex_ceiling_color;
} t_textures;

typedef struct s_map
{
  int   fd;
  char  **file;
  char  **map;
  int   width;
  int   height;
  char *path;
} t_map;

typedef struct s_player
{
  int   x;
  int   y;
  char dir;
} t_player;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
    void        *mlx;
    void        *win;
    int         win_height;
    int         win_width;
	bool		should_close;
	t_img		frame;
    t_map       map;
    t_player    player;
    size_t		keys;
    t_textures  textures;
} t_data;

#define FT_WIDTH 1920

#define FT_HEIGHT 1080

//PARSER
int		check_cub(char *filename);

//INIT
int		init(t_data *data);

//INPUT
void 	key_press(int keycode, t_data *data);
void 	key_release(int keycode, t_data *data);

//UTILS
char *skip_spaces(char *str);
int  is_identifier(char *line, char *id);
t_identifier get_identifier(char *line);
void	free_split(char **split);

//PARSER
int check_cub(char *filename);
int check_xpm(char *filename);
int load_file(t_data *data, char *path);
int parse_textures(t_data *data);
int parse_colors(t_data *data);

#endif
