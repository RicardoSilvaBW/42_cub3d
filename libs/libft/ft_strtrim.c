/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:47:45 by rjorge-p          #+#    #+#             */
/*   Updated: 2025/04/15 18:04:03 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_trim(char const s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (to_trim(s1[i], set))
		i++;
	while (to_trim(s1[j], set))
		j--;
	ret = ft_substr(s1, i, (j - i + 1));
	return (ret);
}
