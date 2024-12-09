/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasniets <thomasniets@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:40:22 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/12/06 23:29:36 by thomasniets      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_success(t_game *game)
{
	free_game(game);
	delete_images(game);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}

void	error(t_game *game)
{
	ft_printf("Error\n%s\n", mlx_strerror(mlx_errno));
	// needs 2 stderror ft_putstr_fd(str, 2)
	free_game(game);
	delete_images(game);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit(EXIT_FAILURE);
}

int	error_message(char *str)
{
	ft_putendl_fd(str, 2);
	return (EXIT_FAILURE);
}

void	print_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		ft_printf("%s\n", arr[i]);
		i++;
	}
}
