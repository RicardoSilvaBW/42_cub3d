/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:04:23 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/05/22 14:45:44 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	main_loop(t_data *data)
{
    clear_image(data);
    render_walls(data);
    mlx_put_image_to_window(data->mlx, data->win, data->frame.img, 0, 0);
}

int main(int argc, char **argv)
{
    static t_data   data;
    
    if (argc != 2)
        return (write(2, "Error: Use ./cub3d <map.cub>.\n", 26), EXIT_FAILURE);
    if (init(&data, argv))
        exit(EXIT_FAILURE);
	  mlx_loop_hook(data.mlx, main_loop, &data);
	  mlx_loop(data.mlx);
    return (0);
}

