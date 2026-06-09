/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <<rjorge-p@student.42.fr> >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:00:00 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/06/08 12:00:00 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

static int	is_blank_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	if (line[0] == '\n')
		return (1);
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	is_header_line(char *line)
{
	t_identifier	id;

	id = get_identifier(line);
	if (id != ID_NONE)
		return (1);
	return (is_blank_line(line));
}

static int	find_map_start(char **file)
{
	int	i;

	i = 0;
	while (file[i] && is_header_line(file[i]))
		i++;
	return (i);
}

static int	check_blank_line(char **file, int start)
{
	int	i;

	i = start;
	while (file[i])
	{
		if (is_blank_line(file[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	strip_newlines(char **map)
{
	int	i;
	int	len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			map[i][len -1] = '\0';
		i++;
	}
	return (1);
}

int	set_map(t_data *data)
{
	int	i;
	int	len;
	int	start;

	start = find_map_start(data->map.file);
	if (!data->map.file[start])
		return (write(2, "Error: No map found.\n", 21), 0);
	if (check_blank_line(data->map.file, start))
		return (write(2, "Error: Blank line in map.\n", 26), 0);
	data->map.map = &data->map.file[start];
	strip_newlines(data->map.map);
	i = 0;
	data->map.width = 0;
	while (data->map.map[i])
	{
		len = (int)ft_strlen(data->map.map[i]);
		if (len > data->map.width)
			data->map.width = len;
		i++;
	}
	data->map.height = i;
	return (1);
}
