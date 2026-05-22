/* ************************************************************************** */
/*                                                                            */
 /*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:34:03 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/05/22 13:52:24 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int  validate_rgb(char **split)
{
    int i;
    int value;

    if (!split[0] || !split[1] || !split[2] || split[3])
        return (ft_printf("Error: Invalid RGB format.\n"), 0);
    i = 0;
    while (i < 3)
    {
        value = ft_atoi(split[i]);
        if (value < 0 || value > 255)
            return (ft_printf("Error: RGB values must be between 0 and 255.\n"), 0);
        i++;
    }
    return (1);
}

static int  parse_rgb(int color[3], char *rgb)
{
    char    **split;

    split = ft_split(rgb, ',');
    if (!split)
        return (0);
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
        return (ft_printf("Error: Repeated color identifier.\n"), 0);
    if (*rgb_string == '\0' || *rgb_string == '\n')
        return (ft_printf("Error: Missing RGB values.\n"), 0);
    if (!parse_rgb(color, rgb_string))
        return (0);
    *flag = 1;
    return (1);
}

static int  parse_color_line(t_data *data, char *line)
{
    char            *rgb; 
    t_identifier    id;
    
    line = skip_spaces(line);
    id = get_identifier(line);
    if (id == ID_NONE)
        return (1);
    rgb = skip_spaces(line + 1);
    if (id == ID_F)
        return (store_color(data->textures.floor, &data->textures.floor_set, rgb));
    else if (id == ID_C)
        return (store_color(data->textures.ceiling, &data->textures.ceiling_set, rgb));
    return (1);
}

int parse_colors(t_data *data)
{
    int i;

    i = 0;
    while (data->map.file[i])
    {
        if (!parse_color_line(data, data->map.file[i]))
            return (0);
        i++;
    }
    if (!data->textures.floor_set)
        return (ft_printf("Error: Missing floor color.\n"), 0);
    if (!data->textures.ceiling_set)
        return (ft_printf("Error: Missing ceiling color.\n"), 0);
    return (1);
}
