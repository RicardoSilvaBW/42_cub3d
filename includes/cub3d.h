/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:26:07 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/05/18 14:16:53 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
#include "mlx.h"

#include <stdbool.h>
//STRUCTS

typedef struct s_textures
{
  char          *north;
  char          *south;
  char          *west;
  char          *east;
  int           *floor;
  int           *ceiling;
  unsigned long hex_floor_color;
  unsigned long hex_ceiling_color;
  int           x;
  int           y;
} t_textures;

typedef struct s_map
{
  int   fd;
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

#endif
