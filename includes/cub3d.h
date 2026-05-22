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
#include "minilibx/mlx.h"
#include <fcntl.h>
#include <stdlib.h>

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

typedef struct s_data
{
    void        *mlx;
    void        *win;
    int         win_height;
    int         win_width;
    t_map       map;
    t_player    player;
    t_textures  textures;
} t_data;

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
