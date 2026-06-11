/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:04:23 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/06/03 17:10:08 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx.h"
#include <stdlib.h>

#include <X11/Xlib.h>

static void	update(t_data *data)
{
	handle_movement(data);
	if (data->keys & (key_left))
		rotate_player(&data->player, -FT_ROT_SPEED);
	if (data->keys & (key_right))
		rotate_player(&data->player, FT_ROT_SPEED);
}

int	main_loop(t_data *data)
{
	if (!data->paused)
	{
		update(data);
		raycasting(data);
		mlx_put_image_to_window(data->mlx, data->win, data->frame.img, 0, 0);
		mlx_mouse_move(data->mlx, data->win, FT_WIDTH / 2, FT_HEIGHT / 2);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	static t_data	data;

	if (argc != 2)
		return (write(2, "Error: Use ./cub3d <map.cub>.\n", 30), EXIT_FAILURE);
	if (init(&data, argv))
		return (EXIT_FAILURE);
	mlx_loop(data.mlx);
	clean(&data);
	return (EXIT_SUCCESS);
}
