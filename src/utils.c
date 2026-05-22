/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:14:16 by feazeved          #+#    #+#             */
/*   Updated: 2026/05/22 11:15:06 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= FT_HEIGHT || y >= FT_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	clear_image(t_data *data)
{
	int	x;
	int	y;

	if (!data || !data->frame.addr)
		return ;
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			if (y < data->win_height / 2)
				put_pixel(&data->frame, x, y, data->textures.hex_ceiling_color);
			else
				put_pixel(&data->frame, x, y, data->textures.hex_floor_color);
			x++;
		}
		y++;
	}
}
