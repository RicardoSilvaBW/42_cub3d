/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 10:43:29 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/05/22 11:05:17 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int  count_lines(char *path)
{
    int     fd;
    int     lines;
    char    *line;

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error: file not found\n");
        exit(0);
    }
    lines = 0;
    line = get_next_line(fd);
    while (line)
    {
        lines++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return(lines);
}

int load_file(t_data *data, char *path)
{
    int     lines;
    int     fd;
    char    *line;
    int     i;

    lines = count_lines(path);
    if (lines < 0)
        return (0);
    data->map.file = malloc(sizeof(char *) * (lines + 1));
    if (!data->map.file)
        return (0);
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (ft_printf("Error: file not found\n"), 1);
    i = 0;
    line = get_next_line(fd);
    while (line)
    {
        data->map.file[i++] = line;
        line = get_next_line(fd);
    }
    data->map.file[i] = NULL;
    close(fd);
    return (1);
}
