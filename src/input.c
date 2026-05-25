/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:14:16 by feazeved          #+#    #+#             */
/*   Updated: 2026/05/22 11:15:06 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "cub3d.h"
//
static void stt_key_event(int keycode, t_data *data)
{
    if (keycode == XK_Escape)
    {
		// close and free (exit?)
		return ;
	}
}

void  key_press(int keycode, t_data *data)
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

void  key_release(int keycode, t_data *data)
{
    stt_key_event(keycode, data);
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

