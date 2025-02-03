/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:40:04 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/11/28 10:11:54 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (c == '%')
		return (ft_print_char('%'));
	if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (c == 'i' || c == 'd')
		return (ft_print_int(va_arg(args, int)));
	if (c == 'p')
		return (ft_print_address(va_arg(args, void *)));
	if (c == 'u')
		return (ft_putnbr_uint(va_arg(args, unsigned int),
				10, "0123456789"));
	if (c == 'x')
		return (ft_putnbr_uint(va_arg(args, unsigned int),
				16, "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_uint(va_arg(args, unsigned int),
				16, "0123456789ABCDEF"));
	return (-1);
}

static int	ft_format_check(char c, va_list args)
{
	int	check;

	if (ft_strchr("cspdiuxX%", c))
	{
		check = ft_format(c, args);
		return (check);
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		chars_printed;
	int		check;

	chars_printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check = ft_format_check(*format, args);
		}
		else
			check = ft_print_char(*format);
		if (check < 0)
			return (va_end(args), -1);
		chars_printed += check;
		format++;
	}
	va_end(args);
	return (chars_printed);
}
