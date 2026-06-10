/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:27:52 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/06/10 17:32:50 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	store_texture(char **texture, char *path)
{
	if (*texture != NULL)
		return (write(2, "Error: Repeated texture identifier.\n", 36), 0);
	if (*path == '\0' || *path == '\n')
		return (write(2, "Error: Missing texture path.\n", 29), 0);
	if (!check_xpm(path))
		return (write(2, "Error: Texture file without .xpm extension.\n", 44)
			, 0);
	*texture = ft_strdup(path);
	if (!*texture)
		return (perror("Error"), 0);
	return (1);
}

static int	is_identifier(char *line, char *id)
{
	int	len;

	len = ft_strlen(id);
	if (ft_strncmp(line, id, len) != 0)
		return (0);
	if (line[len] != ' ' && line[len] != '\t')
		return (0);
	return (1);
}

t_identifier	get_identifier(char *line)
{
	if (is_identifier(line, "NO"))
		return (ID_NO);
	if (is_identifier(line, "SO"))
		return (ID_SO);
	if (is_identifier(line, "WE"))
		return (ID_WE);
	if (is_identifier(line, "EA"))
		return (ID_EA);
	if (is_identifier(line, "F"))
		return (ID_F);
	if (is_identifier(line, "C"))
		return (ID_C);
	return (ID_NONE);
}

static int	parse_texture_line(t_data *data, char *line)
{
	char			*path;
	t_identifier	id;

	id = get_identifier(line);
	if (id == ID_NONE)
		return (1);
	line += 2;
	path = line;
	while (*path == ' ')
		path++;
	if (id == ID_NO)
		return (store_texture(&data->textures.north_path, path));
	if (id == ID_SO)
		return (store_texture(&data->textures.south_path, path));
	if (id == ID_WE)
		return (store_texture(&data->textures.west_path, path));
	if (id == ID_EA)
		return (store_texture(&data->textures.east_path, path));
	return (1);
}

int	parse_textures(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.file[i])
	{
		if (!parse_texture_line(data, data->map.file[i]))
			return (0);
		i++;
	}
	if (!data->textures.north_path)
		return (write(2, "Error: Missing NO texture.\n", 27), 0);
	if (!data->textures.south_path)
		return (write(2, "Error: Missing SO texture.\n", 27), 0);
	if (!data->textures.west_path)
		return (write(2, "Error: Missing WE texture.\n", 27), 0);
	if (!data->textures.east_path)
		return (write(2, "Error: Missing EA texture.\n", 27), 0);
	return (1);
}
