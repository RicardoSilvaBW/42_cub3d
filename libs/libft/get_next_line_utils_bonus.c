/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:56:53 by rjorge-p          #+#    #+#             */
/*   Updated: 2025/05/03 14:50:19 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	has_line_break(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	if (buf[i] == -1)
		return (-1);
	return (0);
}

void	shift_buffer(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
		i++;
	while (buf[i])
		buf[j++] = buf[i++];
	while (j < BUFFER_SIZE)
		buf[j++] = 0;
}

void	strcat_line(char *new, char *buf, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str)
	{
		while (str[i])
		{
			new[i] = str[i];
			i++;
		}
	}
	while (buf[j] != '\n' && buf[j])
	{
		new[j + i] = buf[j];
		j++;
	}
	if (buf[j] == '\n')
		new[i + j] = '\n';
	new[i + j + (buf[j] == '\n')] = 0;
}

char	*strjoin_line(char *buf, char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (str)
		while (str[i])
			i++;
	while (buf[j] != '\n' && buf[j])
		j++;
	new = malloc(sizeof(char) * (i + j + (buf[j] == '\n') + 1));
	if (!new)
		return (NULL);
	strcat_line(new, buf, str);
	if (str)
		free(str);
	return (new);
}
