/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:12:02 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/11/28 10:12:51 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(unsigned long long nb, int radix, char *base)
{
	int	count;
	int	result;

	count = 0;
	if (nb >= (unsigned long long)radix)
	{
		result = ft_putnbr (nb / radix, radix, base);
		if (result < 0)
			return (-1);
		count += result;
	}
	if (write (1, &base[nb % radix], 1) < 0)
		return (-1);
	count++;
	return (count);
}

int	ft_putnbr_uint(unsigned int nb, int radix, char *base)
{
	int	count;
	int	result;

	count = 0;
	if (nb >= (unsigned int)radix)
	{
		result = ft_putnbr_uint (nb / radix, radix, base);
		if (result < 0)
			return (-1);
		count += result;
	}
	if (write (1, &base[nb % radix], 1) < 0)
		return (-1);
	count++;
	return (count);
}
