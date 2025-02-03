/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:18:26 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/12/11 14:19:19 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	move_up(t_game *game)
{
	int	target_x;
	int	target_y;

	target_y = game->hero.y - 1;
	target_x = game->hero.x;
	if (move(target_x, target_y, game) == EXIT_SUCCESS)
	{
		game->hero_img->instances[0].y -= 64;
		game->hero.y -= 1;
		ft_printf("moves: %i\n", game->moves);
	}
}

void	move_down(t_game *game)
{
	int	target_x;
	int	target_y;

	target_y = game->hero.y + 1;
	target_x = game->hero.x;
	if (move(target_x, target_y, game) == EXIT_SUCCESS)
	{
		game->hero_img->instances[0].y += 64;
		game->hero.y += 1;
		ft_printf("moves: %i\n", game->moves);
	}
}

void	move_left(t_game *game)
{
	int	target_x;
	int	target_y;

	target_y = game->hero.y;
	target_x = game->hero.x - 1;
	if (move(target_x, target_y, game) == EXIT_SUCCESS)
	{
		game->hero_img->instances[0].x -= 64;
		game->hero.x -= 1;
		ft_printf("moves: %i\n", game->moves);
	}
}

void	move_right(t_game *game)
{
	int	target_x;
	int	target_y;

	target_y = game->hero.y;
	target_x = game->hero.x + 1;
	if (move(target_x, target_y, game) == EXIT_SUCCESS)
	{
		game->hero_img->instances[0].x += 64;
		game->hero.x += 1;
		ft_printf("moves: %i\n", game->moves);
	}
}
