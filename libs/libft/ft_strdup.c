/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:56:47 by rjorge-p          #+#    #+#             */
/*   Updated: 2025/04/15 17:53:11 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;

	ret = malloc((ft_strlen(s) * sizeof(char)) + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s, ft_strlen(s) + 1);
	return (ret);
}
