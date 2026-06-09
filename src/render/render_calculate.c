/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_calculate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <<rjorge-p@student.42.fr> >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:37:34 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/06/09 19:32:44 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double  calculate_wall_x(t_ray *ray, t_player *player)
{
    double  wall_x;

    if (ray->side == 0)
        wall_x = player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
    else
        wall_x = player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
    wall_x -= floor(wall_x);
    return (wall_x);
}

int calculate_tex_x(t_img *texture, t_ray *ray, double wall_x)
{
    int tex_x;

    tex_x = (int)(wall_x * texture->width);
    if (ray->side == 0 && ray->ray_dir_x > 0)
        tex_x = texture->width - tex_x - 1;
    if (ray->side == 1 && ray->ray_dir_y < 0)
        tex_x = texture->width - tex_x - 1;
    return (tex_x);
}
