/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycasting_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:21:49 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/06/10 16:08:04 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

#define WALL_LIGTH 0x00FF00
#define WALL_DARK 0x007700

static void	init_ray(t_ray *ray, t_player *player, int x)
{
    ray->camera_x = 2 * x / (double) FT_WIDTH - 1;
    ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera_x;
    ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera_x;
    ray->map_x = (int)player->pos_x;
    ray->map_y = (int)player->pos_y;
    if (ray->ray_dir_x == 0)
    	ray->delta_dist_x = 1e30;
    else
    	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
    if (ray->ray_dir_y == 0)
    	ray->delta_dist_y = 1e30;
    else
    	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
    ray->hit = 0;
}

static void init_dda(t_ray *ray, t_player *player)
{
    if (ray->ray_dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_dist_x;
    }
    if (ray->ray_dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
    }
}

static void	exec_dda(t_ray *ray, t_data *data)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0 || ray->map_y >= data->map.height || ray->map_x < 0 || ray->map_x >= data->map.width)
		{
			ray->hit = 1;
			break;
		}
		if (data->map.map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}

}

static void	calculate_wall(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(data->win_height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + data->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->win_height / 2;
	if (ray->draw_end >= data->win_height)
		ray->draw_end = data->win_height - 1;
}

static void draw_textured_column(t_data *data, t_ray *ray, t_img *texture, int x, int tex_x)
{
	int				y;
	int				tex_y;
	double			step;
	double			tex_pos;
	unsigned int	color;

	y = 0;
	while (y < ray->draw_start)
		put_pixel(&data->frame, x, y++, data->textures.hex_ceiling_color);

	step = (double)texture->height / ray->line_height;
	tex_pos = (ray->draw_start
			- (double)data->win_height / 2
			+ (double)ray-> line_height / 2) * step;

	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= texture->height)
			tex_y = texture->height - 1;
		color = get_texture_pixel(texture, tex_x, tex_y);
		put_pixel(&data->frame, x, y, color);
		tex_pos += step;
		y++;
	}
	while (y < data->win_height)
		put_pixel(&data->frame, x, y++, data->textures.hex_floor_color);
}

int raycasting(t_data *data)
{
    t_ray   ray;
	t_img	*texture;
	double	wall_x;
	int		tex_x;
    int     x;

    x = 0;
    while (x < FT_WIDTH)
    {
    	init_ray(&ray, &data->player, x);
     	init_dda(&ray, &data->player);
     	exec_dda(&ray, data);
      	calculate_wall(&ray, data);

		texture = get_wall_texture(data, &ray);
		wall_x = calculate_wall_x(&ray, &data->player);
		tex_x = calculate_tex_x(texture, &ray, wall_x);
		draw_textured_column(data, &ray, texture, x, tex_x);
       	x++;
    }
    return (0);
}
