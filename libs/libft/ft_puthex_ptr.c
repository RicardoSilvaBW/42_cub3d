/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:03:42 by rjorge-p          #+#    #+#             */
/*   Updated: 2025/09/29 13:14:56 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_ptr(unsigned long n)
{
	char	*hex;
	char	count;

	hex = "0123456789abcdef";
	count = 0;
	if (n > 15)
		count += ft_puthex_ptr(n / 16);
	write(1, &hex[n % 16], 1);
	count++;
	return (count);
}
