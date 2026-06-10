/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:12:51 by feazeved          #+#    #+#             */
/*   Updated: 2026/06/09 16:11:36 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <unistd.h>
#include <X11/Xlib.h>

#include "cub3d_bonus.h"
#include "mlx.h"

static void	stt_init_hooks(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_hook(data->win, DestroyNotify, 0, mlx_loop_end, data->mlx);
	mlx_loop_hook(data->mlx, main_loop, data);
}

static int	stt_init_mlx(t_data *d)
{
	d->win_width = FT_WIDTH;
	d->win_height = FT_HEIGHT;
	if (d->win_width <= 10 || d->win_height <= 10)
		return (write(2, "Error: Bad window proportions.\n", 31), 1);
	if (load_textures(d))
		return (1);
	d->win = mlx_new_window(d->mlx, d->win_width, d->win_height, "Backrooms");
	if (!d->win)
		return (write(2, "Error: Mlx new window fail.\n", 22), 1);
	d->frame.img = mlx_new_image(d->mlx, d->win_width, d->win_height);
	if (!d->frame.img)
		return (write(2, "Error: Mlx new image fail.\n", 27), 1);
	d->frame.addr = mlx_get_data_addr(d->frame.img, &d->frame.bpp,
			&d->frame.line_len, &d->frame.endian);
	if (!d->frame.addr)
		return (write(2, "Error: Mlx get data addr fail.\n", 31), 1);
	return (0);
}

int	init(t_data *data, char **argv)
{
	data->map.path = argv[1];
	if (!parser(data))
		return (1);
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		write(2, "Error: Mlx init fail.\n", 22);
		clean(data);
		return (1);
	}
	if (stt_init_mlx(data))
		return (clean(data), 1);
	stt_init_hooks(data);
	return (0);
}
