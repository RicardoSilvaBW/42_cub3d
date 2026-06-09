/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <<rjorge-p@student.42.fr> >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:04:23 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/06/03 17:10:08 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <math.h>
#include <stdlib.h>

#include <X11/Xlib.h>

void	rotate_player(t_player *p, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}

int	in_bounds(t_data *data, double x, double y)
{
	return (x >= 0 && (int)x < data->map.width
		&& y >= 0 && (int)y < data->map.height);
}

void	try_move(t_data *data, double move_x, double move_y)
{
	t_player	*p;
	char		**m;

	p = &data->player;
	m = data->map.map;
	if (p->pos_x + move_x * FT_COLLISION_MARGIN < 0
		|| p->pos_x >= data->map.width)
		return ;
	if (in_bounds(data, p->pos_x + move_x * FT_COLLISION_MARGIN, p->pos_y)
		&& m[(int)(p->pos_y)]
		[(int)(p->pos_x + move_x * FT_COLLISION_MARGIN)] != '1')
	{
		p->pos_x += move_x;
	}
	if (in_bounds(data, p->pos_x, p->pos_y + move_y * FT_COLLISION_MARGIN)
		&& m[(int)(p->pos_y + move_y * FT_COLLISION_MARGIN)]
		[(int)(p->pos_x)] != '1')
	{
		p->pos_y += move_y;
	}
}

void	update(t_data *data)
{
	t_player		*p;
	double		move_x;
    double		move_y;
    double		strafe_x;
    double		strafe_y;

	p = &data->player;

	// SPEED

	// MOVEMENT
	move_x = 0;
	move_y = 0;
	strafe_x = p->plane_x / FT_FOV;
    strafe_y = p->plane_y / FT_FOV;
	if (data->keys & (key_w))
	{
		move_x += p->dir_x;
		move_y += p->dir_y;
	}
	if (data->keys & (key_s))
	{
		move_x -= p->dir_x;
		move_y -= p->dir_y;
	}
	if (data->keys & (key_a))
	{
		move_x -= strafe_x;
		move_y -= strafe_y;
	}
	if (data->keys & (key_d))
	{
		move_x += strafe_x;
		move_y += strafe_y;
	}

	if (move_x != 0 || move_y != 0)
        try_move(data, move_x * p->speed, move_y * p->speed);
	// ROTATION
	if (data->keys & (key_left))
		rotate_player(&data->player, -FT_ROT_SPEED);
	if (data->keys & (key_right))
		rotate_player(&data->player, FT_ROT_SPEED);
}

int	main_loop(t_data *data)
{
	update(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.img, 0, 0);
    return (0);
}

int main(int argc, char **argv)
{
    static t_data   data;

    if (argc != 2)
    	return (write(2, "Error: Use ./cub3d <map.cub>.\n", 30), EXIT_FAILURE);
    if (init(&data, argv))
    	return (EXIT_FAILURE);
    mlx_loop(data.mlx);
    clean(&data);
    return (EXIT_SUCCESS);
}
