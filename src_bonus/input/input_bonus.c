/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:14:16 by feazeved          #+#    #+#             */
/*   Updated: 2026/06/03 17:11:23 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "cub3d_bonus.h"
#include "mlx.h"

static void	key_press2(int keycode, t_data *data)
{
	if (keycode == XK_Right)
		data->keys |= (size_t)key_right;
	if (keycode == XK_Left)
		data->keys |= (size_t)key_left;
	if (keycode == XK_Up)
		data->keys |= (size_t)key_up;
	if (keycode == XK_Down)
		data->keys |= (size_t)key_down;
	if (keycode == XK_w)
		data->keys |= (size_t)key_w;
	if (keycode == XK_a)
		data->keys |= (size_t)key_a;
	if (keycode == XK_s)
		data->keys |= (size_t)key_s;
	if (keycode == XK_d)
		data->keys |= (size_t)key_d;
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		return (mlx_loop_end(data->mlx));
	if (keycode == XK_Shift_L)
	{
		data->keys |= (size_t)key_shift;
		data->player.speed = FT_RUN_SPEED;
	}
	if (keycode == XK_p)
	{
		data->paused = !(data->paused);
	}
	key_press2(keycode, data);
	return (0);
}

static void	key_release2(int keycode, t_data *data)
{
	if (keycode == XK_Right)
		data->keys &= ~(size_t)key_right;
	if (keycode == XK_Left)
		data->keys &= ~(size_t)key_left;
	if (keycode == XK_Up)
		data->keys &= ~(size_t)key_up;
	if (keycode == XK_Down)
		data->keys &= ~(size_t)key_down;
	if (keycode == XK_w)
		data->keys &= ~(size_t)key_w;
	if (keycode == XK_a)
		data->keys &= ~(size_t)key_a;
	if (keycode == XK_s)
		data->keys &= ~(size_t)key_s;
	if (keycode == XK_d)
		data->keys &= ~(size_t)key_d;
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == XK_Shift_L)
	{
		data->keys &= ~(size_t)key_shift;
		data->player.speed = FT_MOVE_SPEED;
	}
	key_release2(keycode, data);
	return (0);
}
