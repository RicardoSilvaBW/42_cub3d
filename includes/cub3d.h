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
#include "minilibx/mlx.h"

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

typedef struct s_keys
{
    bool  w;
    bool  a;
    bool  s;
    bool  d;
    bool  up_arrow;
    bool  down_arrow;
    bool  left_arrow;
    bool  right_arrow;
}   t_keys;

typedef struct s_data
{
    void        *mlx;
    void        *win;
    int         win_height;
    int         win_width;
    t_map       map;
    t_player    player;
    t_keys      keys;
    t_textures  textures;
} t_data;

//PARSER
int check_cub(char *filename);

#endif
