/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:46:43 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/05/22 14:30:06 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int  is_identifier(char *line, char *id)
{
    int len;

    len = ft_strlen(id);
    if (ft_strncmp(line, id, len) != 0)
        return (0);
    if (line[len] != ' ' && line[len] != '\t')
        return (0);
    return (1);
}

t_identifier get_identifier(char *line)
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