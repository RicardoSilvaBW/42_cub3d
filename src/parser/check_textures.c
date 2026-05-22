/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:27:52 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/05/22 13:47:52 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int store_texture(char **texture, char *path)
{
    if (*texture != NULL)
        return (ft_printf("Error: Repeated texture identifier.\n"), 0);
    if (*path == '\0' || *path == '\n')
        return (ft_printf("Error: Missing texture path.\n"), 0);
    if (!check_xpm(path))
        return (ft_printf("Error: Texture file without .xpm extension.\n"), 0);
    *texture = ft_strdup(path);
    if (!*texture)
        return (0);
    return (1);
}

static int  parse_texture_line(t_data *data, char *line)
{
    char			*path;
	t_identifier	id;

	line = skip_spaces(line);
	id = get_identifier(line);
	if (id == ID_NONE)
		return (1);
	path = skip_spaces(line + 2);
	if (id == ID_NO)
		return (store_texture(&data->textures.north, path));
	else if (id == ID_SO)
		return (store_texture(&data->textures.south, path));
	else if (id == ID_WE)
		return (store_texture(&data->textures.west, path));
	else if (id == ID_EA)
		return (store_texture(&data->textures.east, path));
	return (1);
}

int parse_textures(t_data *data)
{
    int i;

    i = 0;
    while (data->map.file[i])
    {
        if (!parse_texture_line(data, data->map.file[i]))
            return (0);
        i++;
    }
    if (!data->textures.north)
        return (ft_printf("Error: Missing NO texture.\n"), 0);
    if (!data->textures.south)
        return (ft_printf("Error: Missing SO texture.\n"), 0);
    if (!data->textures.west)
        return (ft_printf("Error: Missing WE texture.\n"), 0);
    if (!data->textures.east)
        return (ft_printf("Error: Missing EA texture.\n"), 0);
    return (1);
}
