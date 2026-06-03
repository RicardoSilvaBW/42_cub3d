/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <<rjorge-p@student.42.fr> >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:21:49 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/06/03 16:53:39 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_raycasting(int px, t_ray *ray, t_player *player)
{
    ray->camera_x = 2 * px / (double) FT_WIDTH - 1;
    ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera_x;
    ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera_x;
    ray->map_x = (int)player->pos_x;
    ray->map_y = (int)player->pos_y;
    ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
    ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
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

int raycasting(t_data *data, t_player *player)
{
    t_ray   ray;
    int     x;
    
    x = 0;
    ray = data->ray;
    //while (x < data->win_width)
    //{
        init_raycasting(x, &ray, player);
        init_dda(&ray, player);

        printf("x = %d\n", x);
	    printf("step_x = %d\n", ray.step_x);
	    printf("step_y = %d\n", ray.step_y);
	    printf("side_dist_x = %f\n", ray.side_dist_x);
	    printf("side_dist_y = %f\n\n", ray.side_dist_y);
        x++;
    //}
    return (0);
}