/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:21:49 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/05/27 14:28:17 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void *init_raycasting(int px, t_ray *ray, t_player *player)
{
    ray->camera_x = 2 * px / (double) FT_WIDTH - 1;
    ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera_x;
    ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera_x;
    ray->map_x = (int)player->pos_x;
    ray->map_y = (int)player->pos_y;
    ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
    ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

int raycasting(t_data *data, t_player *player)
{
    t_ray   ray;
    int     x;
    
    x = 0;
    ray = data->ray;
    while (x < data->win_width)
    {
        init_raycasting(x, &ray, player);
    }
    return (0);
}