/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:47:06 by rjorge-p          #+#    #+#             */
/*   Updated: 2025/04/10 14:47:59 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*occ;

	occ = NULL;
	while (*s)
	{
		if (*s == (char) c)
		{
			occ = (char *)s;
		}
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (occ);
}
