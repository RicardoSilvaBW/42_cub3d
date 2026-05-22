/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:24:05 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/05/22 13:34:26 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_file(t_data *data)
{
    if (!parse_textures(data))
        return (0);
    if (!parse_colors(data))
        return (0);
    /*if (!parse_map(data))
        return (0); */
    return (1);
}