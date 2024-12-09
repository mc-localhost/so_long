/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:22:17 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/11/28 10:11:17 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *s)
{
	if (s == NULL)
		return (ft_print_str("(null)"));
	if (write(1, s, ft_strlen(s)) < 0)
		return (-1);
	return (ft_strlen(s));
}
