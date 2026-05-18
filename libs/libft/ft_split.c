/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:14:07 by rjorge-p          #+#    #+#             */
/*   Updated: 2025/04/15 18:05:10 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

static char	*make_string(char *s, char c)
{
	int		len;
	char	*string;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	string = malloc((len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != c)
	{
		string[len] = s[len];
		len++;
	}
	string[len] = 0;
	return (string);
}

static char	**free_mem(char **strs, int i)
{
	int	n;

	n = 0;
	while (n < i)
	{
		free(strs[n]);
		n++;
	}
	free(strs);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;

	i = 0;
	j = -1;
	strs = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (strs);
	while (++j < count_words(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		strs[j] = make_string((char *)&s[i], c);
		if (!strs[j])
			return (free_mem(strs, j));
		while (s[i] != c && s[i])
			i++;
	}
	strs[j] = 0;
	return (strs);
}
