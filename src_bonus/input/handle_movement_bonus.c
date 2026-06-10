/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:14:16 by feazeved          #+#    #+#             */
/*   Updated: 2026/06/03 17:11:23 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	in_bounds(t_data *data, double x, double y)
{
	return (x >= 0 && (int)x < data->map.width
		&& y >= 0 && (int)y < data->map.height);
}

static void	try_move(t_data *data, double move_x, double move_y)
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

static void	calc_move(t_data *d, double *move_x, double *move_y)
{
	const double	strafe_x = d->player.plane_x / FT_FOV;
	const double	strafe_y = d->player.plane_y / FT_FOV;

	*move_x = 0;
	*move_y = 0;
	if (d->keys & (key_w))
	{
		*move_x += d->player.dir_x;
		*move_y += d->player.dir_y;
	}
	if (d->keys & (key_s))
	{
		*move_x -= d->player.dir_x;
		*move_y -= d->player.dir_y;
	}
	if (d->keys & (key_a))
	{
		*move_x -= strafe_x;
		*move_y -= strafe_y;
	}
	if (d->keys & (key_d))
	{
		*move_x += strafe_x;
		*move_y += strafe_y;
	}
}

void	handle_movement(t_data *data)
{
	const double	speed = data->player.speed;
	double			move_x;
	double			move_y;

	move_x = 0;
	move_y = 0;
	calc_move(data, &move_x, &move_y);
	if (move_x != 0 || move_y != 0)
		try_move(data, move_x * speed, move_y * speed);
}
