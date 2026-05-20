/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:04:23 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/05/18 14:04:25 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void  start_game(t_data *data)
{
    while ()
    {

    }
    mlx_loop(data->mlx);
}

int main(int argc, char **argv)
{
    t_data  data;

    if (argc != 2)
        return (ft_printf("Usage: ./so_long <map.cub>\n"), 1);
    if (!check_cub(argv[1]))
        return (ft_printf("Error: map doesn't have .ber extension\n"), 1);
    if (init())
    {
        // print error and exit
    }
    if (parse())
    {
        // clean, print error and exit
    }
    start_game(&data);
    clean();
    return (0);
}

