/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:24:12 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/06/10 17:44:24 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft/libft.h"

int	is_valid_char(char c)
{
	static const char	lut[256] = {
	['0'] = 1, ['1'] = 1, [' '] = 1, ['N'] = 1, ['S'] = 1, ['W'] = 1,
	['E'] = 1, ['\n'] = 1};

	return (lut[(unsigned char)c]);
}

static int	check_cell_sides(char **m, int i, int j)
{
	if (!j || !m[i][j + 1])
		return (1);
	if (m[i][j - 1] == ' ' || m[i][j - 1] == '\0')
		return (1);
	if (m[i][j + 1] == ' ' || m[i][j + 1] == '\0')
		return (1);
	return (0);
}

static int	check_cell_rows(char **m, int i, int j, int max_y)
{
	if (!i || i == max_y)
		return (1);
	if ((int)ft_strlen(m[i - 1]) <= j)
		return (1);
	if (m[i - 1][j] == ' ' || m[i - 1][j] == '\0')
		return (1);
	if ((int)ft_strlen(m[i + 1]) <= j)
		return (1);
	if (m[i + 1][j] == ' ' || m[i + 1][j] == '\0')
		return (1);
	return (0);
}

int	check_cell(char **m, int i, int j, int max_y)
{
	if (m[i][j] == '0' || ft_strchr("NSWE", m[i][j]))
	{
		if (check_cell_sides(m, i, j))
			return (1);
		if (check_cell_rows(m, i, j, max_y))
			return (1);
	}
	return (0);
}

int	strip_newlines(char **map)
{
	int	i;
	int	len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			map[i][len -1] = '\0';
		i++;
	}
	return (1);
}
