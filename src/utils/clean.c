/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:12:51 by feazeved          #+#    #+#             */
/*   Updated: 2026/06/09 15:47:03 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

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
    if (data->textures.north_path)
        free(data->textures.north_path);
    if (data->textures.south_path)
        free(data->textures.south_path);
    if (data->textures.west_path)
        free(data->textures.west_path);
    if (data->textures.east_path)
        free(data->textures.east_path);
}

void    clean(t_data *data)
{
	free_parse(data);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx && data->textures.north.img)
        mlx_destroy_image(data->mlx, data->textures.north.img);
    if (data->mlx && data->textures.south.img)
        mlx_destroy_image(data->mlx, data->textures.south.img);
    if (data->mlx && data->textures.west.img)
        mlx_destroy_image(data->mlx, data->textures.west.img);
    if (data->mlx && data->textures.east.img)
        mlx_destroy_image(data->mlx, data->textures.east.img);
    if (data->mlx && data->frame.img)
		mlx_destroy_image(data->mlx, data->frame.img);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
}
