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
#include <stdlib.h>

#include <X11/Xlib.h>

void	update(t_data *data)
{
	if (data->keys & (key_w))
		data->player.pos_x -= 0.05;
	if (data->keys & (key_d))
		data->player.pos_y -= 0.05;
	if (data->keys & (key_s))
		data->player.pos_x += 0.05;
	if (data->keys & (key_a))
		data->player.pos_y += 0.05;

}

int	main_loop(t_data *data)
{
	//update according to keys being pressed
	update(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.img, 0, 0);
    return (0);
}

int main(int argc, char **argv)
{
    static t_data   data;

    if (argc != 2)
    	return (write(2, "Error: Use ./cub3d <map.cub>.\n", 26), EXIT_FAILURE);
    if (init(&data, argv))
    	return (EXIT_FAILURE);
    mlx_loop(data.mlx);
    clean(&data);
    return (EXIT_SUCCESS);
}
