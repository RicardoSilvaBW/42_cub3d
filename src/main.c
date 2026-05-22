/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:04:23 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/05/22 14:13:48 by rjorge-p         ###   ########.fr       */
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
    ft_printf("Texture parsing successful!\n\n");
	ft_printf("NO: %s", data.textures.north);
	ft_printf("SO: %s", data.textures.south);
	ft_printf("WE: %s", data.textures.west);
	ft_printf("EA: %s", data.textures.east);

    if (!parse_colors(&data))
        return (1);

    ft_printf("Floor: %d,%d,%d\n",
	data.textures.floor[0],
	data.textures.floor[1],
	data.textures.floor[2]);

    ft_printf("Ceiling: %d,%d,%d\n",
	data.textures.ceiling[0],
	data.textures.ceiling[1],
	data.textures.ceiling[2]);
    
    return (0);
}

