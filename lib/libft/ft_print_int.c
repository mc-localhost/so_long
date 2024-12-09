/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:36:31 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/11/28 10:11:31 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_min(void)
{
	if (write(1, "-2147483648", 11) < 0)
		return (-1);
	return (11);
}

int	ft_print_int(int n)
{
	int	count;
	int	result;

	count = 0;
	if (n == -2147483648)
		return (ft_int_min());
	if (n < 0)
	{
		if (ft_print_char ('-') < 0)
			return (-1);
		count++;
		n = -1 * n;
	}
	if (n >= 10)
	{
		result = ft_print_int (n / 10);
		if (result < 0)
			return (-1);
		count += result;
	}
	if (ft_print_char (n % 10 + '0') < 0)
		return (-1);
	return (++count);
}
