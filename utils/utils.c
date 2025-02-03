/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:40:22 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/12/12 12:48:00 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// void	exit_success(t_game *game)
void	exit_success(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_game(game);
	delete_images(game);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}

// void	error(t_game *game)
void	error(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_putendl_fd("Error\nmlx rendering error", 2);
	free_game(game);
	delete_images(game);
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
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
