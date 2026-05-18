/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p <rjorge-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:13:20 by rjorge-p          #+#    #+#             */
/*   Updated: 2025/09/29 13:15:23 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *ptr)
{
	unsigned long	add;
	int				count;

	count = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	add = (unsigned long) ptr;
	count += ft_putstr("0x");
	count += ft_puthex_ptr(add);
	return (count);
}
