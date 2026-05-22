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

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
    t_data data;

    ft_memset(&data, 0, sizeof(t_data));
    
    if (argc != 2)
        return (ft_printf("Usage: ./so_long <map.cub>\n"), 1);
    if (!check_cub(argv[1]))
        return (ft_printf("Error: Map must have .cub extension."));
    data.map.path = argv[1];
    if (!load_file(&data, argv[1]))
        return (1);
    if (!parse_textures(&data))
        return (1);
    if (!parse_colors(&data))
        return (1);
    if (init(&data))
    {
        exit(EXIT_FAILURE);
    }
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
    clean();
    return (0);
}

