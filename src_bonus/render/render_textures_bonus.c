/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:59:00 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/06/10 16:42:36 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img   *get_wall_texture(t_data *data, t_ray *ray)
{
    if (ray->side == 0)
    {
        if (ray->ray_dir_x > 0)
            return (&data->textures.west);
        return (&data->textures.east);
    }
    if (ray->ray_dir_y > 0)
        return (&data->textures.north);
    return (&data->textures.south);
}

static int  load_texture(t_data *data, t_img *texture, char *path)
{
	int len = ft_strlen(path);
	if (len > 0 && path[len - 1] == '\n')
		path[len - 1] = '\0';
    texture->img = mlx_xpm_file_to_image(data->mlx, path, &texture->width, &texture->height);
    if (!texture->img)
        return (write(STDERR_FILENO, "Error: Failed to load texture.\n", 31), EXIT_FAILURE);
    texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, &texture->line_len, &texture->endian);
    if (!texture->addr)
        return (write(STDERR_FILENO, "Error: Failed to get texture dara.\n", 35), 1);
    return (0);
}

int    load_textures(t_data *data)
{
    if (load_texture(data, &data->textures.north, data->textures.north_path))
        return (EXIT_FAILURE);
    if (load_texture(data, &data->textures.south, data->textures.south_path))
        return (EXIT_FAILURE);
    if (load_texture(data, &data->textures.west, data->textures.west_path))
        return (EXIT_FAILURE);
    if (load_texture(data, &data->textures.east, data->textures.east_path))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

unsigned int    get_texture_pixel(t_img *texture, int tex_x, int tex_y)
{
    char    *pixel;

    pixel = texture->addr + tex_y 
        * texture->line_len 
            + tex_x * (texture->bpp / 8);
    return (*(unsigned int *) pixel);
}