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
	// maybe need a hook for clean when esc
}

static int  stt_init_mlx(t_data *data)
{
    data->win_width = FT_WIDTH;
    data->win_height = FT_HEIGHT;
    if (data->win_width <= 10 || data->win_height <= 10)
        return (write(2, "Error: Bad window proportions.\n", 31), 1);
    data->mlx = mlx_init();
    if (!data->mlx)
        return (write(2, "Error: Mlx init fail.\n", 22), 1);
    data->win = mlx_new_window(data->mlx, data->win_width, data->win_height, "Backrooms");
    if (!data->win)
    {
        mlx_destroy_display(data->mlx);
        write(2, "Error: Mlx new window fail.\n", 28);
        return (1);
    }
    data->frame.img = mlx_new_image(data->mlx, data->win_width, data->win_height);
    if (!data->frame.img)
        return (write(2, "Error: Mlx new image fail.\n", 27), 1);
    data->frame.addr = mlx_get_data_addr(data->frame.img, &data->frame.bpp, &data->frame.line_len, &data->frame.endian);
    if (!data->frame.addr)
        return (write(2, "Error: Mlx get data addr fail.\n", 31), 1);
    return (0);
}

int init(t_data *data, char **argv)
{
    data->map.path = argv[1];
    if (!parser(data))
        return (1);
    if (stt_init_mlx(data))
        return (1);
    stt_init_hooks(data);
    return (0);
}

