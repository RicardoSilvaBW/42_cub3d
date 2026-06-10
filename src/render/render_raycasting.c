/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:21:49 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/06/09 19:40:27 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void	init_dda(t_ray *r, t_player *player)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (player->pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - player->pos_x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (player->pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - player->pos_y) * r->delta_dist_y;
	}
}

static void	exec_dda(t_ray *r, const t_map *map)
{
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (r->map_y < 0 || r->map_y >= map->height
			|| r->map_x < 0 || r->map_x >= map->width)
		{
			r->hit = 1;
			break ;
		}
		if (map->map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}

static void	\
draw_textured_column(t_data *d, t_img *texture, int x, int tex_x)
{
	int				y;
	int				tex_y;
	const double	step = (double)texture->height / d->ray.line_height;
	double			tex_pos;
	unsigned int	color;

	y = 0;
	while (y < d->ray.draw_start)
		put_pixel(&d->frame, x, y++, d->textures.hex_ceiling_color);
	tex_pos = (d->ray.draw_start - (double)d->win_height / 2
			+ (double)d->ray.line_height / 2) * step;
	while (y <= d->ray.draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= texture->height)
			tex_y = texture->height - 1;
		color = get_texture_pixel(texture, tex_x, tex_y);
		put_pixel(&d->frame, x, y, color);
		tex_pos += step;
		y++;
	}
	while (y < d->win_height)
		put_pixel(&d->frame, x, y++, d->textures.hex_floor_color);
}

int	raycasting(t_data *data)
{
	t_img	*texture;
	double	wall_x;
	int		tex_x;
	int		x;

	x = 0;
	while (x < FT_WIDTH)
	{
		init_ray(&data->ray, &data->player, x);
		init_dda(&data->ray, &data->player);
		exec_dda(&data->ray, &data->map);
		calculate_wall_dist(&data->ray, data);
		texture = get_wall_texture(data, &data->ray);
		wall_x = calculate_wall_x(&data->ray, &data->player);
		tex_x = calculate_tex_x(texture, &data->ray, wall_x);
		draw_textured_column(data, texture, x, tex_x);
		x += 2;
	}
	return (0);
}
