/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:34:03 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/06/10 17:22:33 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	validate_rgb(char **split)
{
	int	i;
	int	value;

	if (!split[0] || !split[1] || !split[2] || split[3])
		return (write(2, "Error: Invalid RGB format.\n", 27), 0);
	i = 0;
	while (i < 3)
	{
		value = ft_atoi(split[i]);
		if (value < 0 || value > 255)
			return (write(2, "Error: RGB values must be between 0 and 255.\n"
					, 45), 0);
		i++;
	}
	return (1);
}

static int	parse_rgb(int color[3], char *rgb)
{
	char	**split;

	split = ft_split(rgb, ',');
	if (!split)
		return (perror("Error"), 0);
	if (!validate_rgb(split))
		return (free_split(split), 0);
	color[0] = ft_atoi(split[0]);
	color[1] = ft_atoi(split[1]);
	color[2] = ft_atoi(split[2]);
	free_split(split);
	return (1);
}

static int	store_color(int color[3], int *flag, char *rgb_string)
{
	if (*flag)
		return (write(2, "Error: Repeated color identifier.\n", 34), 0);
	if (*rgb_string == '\0' || *rgb_string == '\n')
		return (write(2, "Error: Missing RGB values.\n", 27), 0);
	if (!parse_rgb(color, rgb_string))
		return (0);
	*flag = 1;
	return (1);
}

static int	parse_color_line(t_data *data, char *line)
{
	char			*rgb;
	t_identifier	id;

	id = get_identifier(line);
	if (id == ID_NONE)
		return (1);
	line += 2;
	rgb = line;
	while (*rgb == ' ')
		rgb++;
	if (id == ID_F)
		return (store_color(data->textures.floor,
				&data->textures.floor_set, rgb));
	else if (id == ID_C)
		return (store_color(data->textures.ceiling,
				&data->textures.ceiling_set, rgb));
	return (1);
}

int	parse_colors(t_data *data)
{
	int			i;
	t_textures	*t;

	i = 0;
	while (data->map.file[i])
	{
		if (!parse_color_line(data, data->map.file[i]))
			return (0);
		i++;
	}
	if (!data->textures.floor_set)
		return (write(2, "Error: Missing floor color.\n", 28), 0);
	if (!data->textures.ceiling_set)
		return (write(2, "Error: Missing ceiling color.\n", 30), 0);
	t = &data->textures;
	t->hex_floor_color = ((t->floor[0] << 16)
			| (t->floor[1] << 8) | (t->floor[2]));
	t->hex_ceiling_color = ((t->ceiling[0] << 16)
			| (t->ceiling[1] << 8) | (t->ceiling[2]));
	return (1);
}
