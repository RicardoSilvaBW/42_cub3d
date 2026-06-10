/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:24:05 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/06/10 17:40:39 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_lines(char *path)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), -1);
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

static int	load_file(t_data *data, char *path)
{
	const int	num_lines = count_lines(path);
	int			fd;
	char		*line;
	int			i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	data->map.file = malloc(sizeof(char *) * (num_lines + 1));
	if (!data->map.file)
		return (perror("Error"), 0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		data->map.file[i++] = line;
		line = get_next_line(fd);
	}
	data->map.file[i] = NULL;
	close(fd);
	if (i != num_lines)
		free_split(data->map.file);
	return (1);
}

int	parser(t_data *data)
{
	if (!check_cub(data->map.path))
		return (write(2, "Error: File not with .cub extension\n", 36), 0);
	if (!load_file(data, data->map.path))
		return (0);
	if (!parse_textures(data) || !parse_colors(data))
		return (free_parse(data), 0);
	if (!set_map(data))
		return (free_parse(data), 0);
	if (!parse_map(data))
		return (free_parse(data), 0);
	return (1);
}
