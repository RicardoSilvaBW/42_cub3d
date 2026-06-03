/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <<rjorge-p@student.42.fr> >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:14:16 by feazeved          #+#    #+#             */
/*   Updated: 2026/06/03 17:49:59 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static const char	lut[256] = {
		['0'] = 1, ['1'] = 1, [' '] = 1, ['N'] = 1, ['S'] = 1, ['W'] = 1,
		['E'] = 1};

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
			if (!lut[(unsigned char)data->map.map[i][j]])
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

	i = -1;
	m = data->map.map;
	while (m[++i])
	{
		j = -1;
		while (m[i][++j])
		{
			if (lut[(unsigned char)data->map.map[i][j]])
			{
				if (!i || i == max_y || !j || !m[i][j + 1])
					return (1);
				if (m[i][j - 1] == ' ' || m[i][j + 1] == ' ')
					return (1);
				if ((int)ft_strlen(m[i - 1]) <= j || m[i - 1][j] == ' ')
					return (1);
				if ((int)ft_strlen(m[i + 1]) <= j || m[i + 1][j] == ' ')
					return (1);
			}
		}
	}
	return (0);
}

int parse_map(t_data *data)
{
	int	num_player;
	int	max_y;

	num_player = 0;
	if (check_elements_and_player(data, &num_player) || num_player != 1)
		return (write(2, "Error: Invalid map elements.\n", 29), 1);
	max_y = 0;
	while (data->map.map[max_y])
		max_y++;
	max_y--;
	if (check_walls(data, max_y))
		return (write(2, "Error: Invalid map.\n", 20), 1);
    return (0);
}
