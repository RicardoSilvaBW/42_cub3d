/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:04:23 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/05/22 11:15:20 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	main_loop(t_data *data)
{
	while (!data->should_close)
	{
		
	}
}

int main(int argc, char **argv)
{
    static t_data   data;

    if (argc != 2)
        return (ft_printf("Usage: ./so_long <map.cub>\n"), 1);
    if (!check_cub(argv[1]))
        return (ft_printf("Error: map doesn't have .ber extension\n"), 1);
    if (init(&data))
    {
        exit(EXIT_FAILURE);
    }
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
    clean();
    return (0);
}

