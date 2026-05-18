/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:12:11 by rjorge-p          #+#    #+#             */
/*   Updated: 2025/05/03 14:52:24 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[4096][BUFFER_SIZE + 1];
	char		*str;
	int			bytes;

	if (fd < 0 || fd > 4096)
		return (0);
	str = 0;
	str = strjoin_line(buffer[fd], str);
	while (!has_line_break(buffer[fd]))
	{
		bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes < 0 || !buffer[fd][0])
		{
			shift_buffer(buffer[fd]);
			return (free(str), NULL);
		}
		if (bytes == 0)
			break ;
		if (bytes < BUFFER_SIZE)
			buffer[fd][bytes] = 0;
		str = strjoin_line(buffer[fd], str);
	}
	shift_buffer(buffer[fd]);
	return (str);
}
