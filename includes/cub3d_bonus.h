/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:26:07 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/06/09 17:41:07 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "libft/libft.h"
# include "mlx.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <stdio.h>

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
}	t_identifier;

enum e_keys
{
	key_w = 1u,
	key_a = 1u << 1,
	key_s = 1u << 2,
	key_d = 1u << 3,
	key_up = 1u << 4,
	key_down = 1u << 5,
	key_left = 1u << 6,
	key_right = 1u << 7,
	key_shift = 1u << 8
};

//STRUCTS

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_textures
{
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	t_img			north;
	t_img			south;
	t_img			west;
	t_img			east;
	int				floor[3];
	int				ceiling[3];
	int				floor_set;
	int				ceiling_set;
	unsigned long	hex_floor_color;
	unsigned long	hex_ceiling_color;
}	t_textures;

typedef struct s_map
{
	int		fd;
	char	**file;
	char	**map;
	int		width;
	int		height;
	char	*path;
}	t_map;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	speed;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	int			paused;
	t_img		frame;
	t_map		map;
	t_player	player;
	t_ray		ray;
	size_t		keys;
	t_textures	textures;
}	t_data;

# define FT_WIDTH 1920

# define FT_HEIGHT 1080

# define FT_FOV 0.66

# define FT_MOVE_SPEED 0.03
# define FT_RUN_SPEED 0.07

# define FT_ROT_SPEED 0.03

# define FT_COLLISION_MARGIN 1.5

//PARSER
int				parser(t_data *data);
int				check_cub(char *filename);
int				check_xpm(char *filename);
int				parse_textures(t_data *data);
int				parse_colors(t_data *data);
int				parse_map(t_data *data);
int				check_cell(char **m, int i, int j, int max_y);
int				is_valid_char(char c);
int				set_map(t_data *data);
t_identifier	get_identifier(char *line);
int				strip_newlines(char **map);

//INIT
int				init(t_data *data, char **argv);

//INPUT
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_data *data);
void			handle_movement(t_data *data);

void			rotate_player(t_player *p, double angle);
int				handle_mouse(int x, int y, t_data *d);

//CLEAN
void			free_split(char **split);
void			free_parse(t_data *data);
void			clean(t_data *data);
int				close_window(t_data *data);

//DRAWING_UTILS
void			put_pixel(t_img *img, int x, int y, int color);
void			clear_image(t_data *data);

//RAYCASTING
int				raycasting(t_data *data);
int				main_loop(t_data *data);
int				load_textures(t_data *data);
t_img			*get_wall_texture(t_data *data, t_ray *ray);
double			calculate_wall_x(t_ray *ray, t_player *player);
int				calculate_tex_x(t_img *texture, t_ray *ray, double wall_x);
void			calculate_wall_dist(t_ray *ray, t_data *data);
unsigned int	get_texture_pixel(t_img *texture, int tex_x, int tex_y);

#endif
