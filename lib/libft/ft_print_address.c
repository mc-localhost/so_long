/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:58:34 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/11/28 10:11:44 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digits(unsigned long long n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits ++;
		n /= 16;
	}
	if (digits > 0)
		return (digits);
	else
		return (-3);
}

int	ft_print_address(void *p)
{
	if (p == NULL)
		return (ft_print_str("0x0"));
	if (ft_print_str("0x") < 0)
		return (-1);
	if (ft_putnbr((unsigned long long)p, 16, "0123456789abcdef") < 0)
		return (-1);
	return (ft_digits((unsigned long long)p) + 2);
}
