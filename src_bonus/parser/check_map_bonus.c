/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:14:16 by feazeved          #+#    #+#             */
/*   Updated: 2026/06/10 16:06:44 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_dir_plane(t_data *data)
{
	if (data->player.dir == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
	}
	else if (data->player.dir == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
	}
	else if (data->player.dir == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
	else if (data->player.dir == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
	}
	data->player.plane_x = -data->player.dir_y * FT_FOV;
	data->player.plane_y = data->player.dir_x * FT_FOV;
}

static void	save_coords(t_data *data, int i, int j, int *num_player)
{
	(*num_player)++;
	data->player.pos_x = j + 0.5;
	data->player.pos_y = i + 0.5;
	data->player.speed = FT_MOVE_SPEED;
	init_dir_plane(data);
}

static int	check_elements_and_player(t_data *data, int *num_player)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (!is_valid_char(data->map.map[i][j]))
				return (1);
			if (ft_strchr("NSWE", data->map.map[i][j]))
			{
				data->player.dir = data->map.map[i][j];
				save_coords(data, i , j, num_player);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_walls(t_data *data, int max_y)
{
	int		i;
	int		j;
	char	**m;

	i = 0;
	m = data->map.map;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (check_cell(m, i, j, max_y))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int parse_map(t_data *data)
{
	int	num_player;
	int	max_y;

	num_player = 0;
	if (check_elements_and_player(data, &num_player) || num_player != 1)
		return (write(2, "Error: Invalid map elements.\n", 29), 0);
	max_y = 0;
	while (data->map.map[max_y])
		max_y++;
	max_y--;
	if (check_walls(data, max_y))
		return (write(2, "Error: Invalid map.\n", 20), 0);
    return (1);
}
