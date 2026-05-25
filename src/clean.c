/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:12:51 by feazeved          #+#    #+#             */
/*   Updated: 2026/05/22 11:14:07 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **split)
{
    int	i;

    if (!split)
        return ;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

void  free_parse(t_data *data)
{
    if (data->map.file)
        free_split(data->map.file);
    if (data->textures.north)
        free(data->textures.north);
    if (data->textures.south)
        free(data->textures.south);
    if (data->textures.west)
        free(data->textures.west);
    if (data->textures.east)
        free(data->textures.east);
}

void    clean(t_data *data)
{
    if (data && data->mlx)
    {
        //destroy image
        mlx_destroy_window(data->mlx, data->win);
        mlx_destroy_display(data->mlx);
    }
    free_parse(data);
}
