/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:12:51 by feazeved          #+#    #+#             */
/*   Updated: 2026/05/22 11:14:07 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <X11/Xlib.h>

#include "cub3d.h"
#include "libft.h"


static void stt_init_hooks(t_data *data)
{
    mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
    mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release, data);
    mlx_hook(data->win, 17, 0, clean(), data);
}

static int  stt_init_mlx(t_data *data)
{
	data->win_width = 1920;
    data->win_height = 1080;
    data->mlx = mlx_init();
    if (!data->mlx)
    {
        write(2, "Error: mlx init fail.\n", 22);
        return (1);
    }
    data->win = mlx_new_window(data->mlx, data->win_width, data->win_height, "Backrooms");
    if (!data->win)
    {
        mlx_destroy_display(data->mlx);
        write(2, "Error: mlx new window fail.\n", 28);
        return (1);
    }
    stt_init_hooks(data);
    return (0);
}

int init(t_data *data)
{
    if (stt_init_mlx(data))
        return (1);
    if (parse(data))
        return (1);
    return (0);
}
