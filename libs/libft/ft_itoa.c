/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:55:31 by rjorge-p          #+#    #+#             */
/*   Updated: 2025/09/29 13:45:56 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	int_len(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_nbr(int n, char *str, int index)
{
	if (n > 9)
		ft_nbr(n / 10, str, index - 1);
	str[index] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	int		count;
	char	*str;
	int		nb;

	nb = n;
	count = int_len(n);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		n *= -1;
	str = malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[count] = '\0';
	if (nb < 0)
		str[0] = '-';
	ft_nbr(n, str, count - 1);
	return (str);
}
