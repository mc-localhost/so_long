/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasniets <thomasniets@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:37:03 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/12/06 23:40:00 by thomasniets      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	move_hero_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		move_up(game);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		move_down(game);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		move_left(game);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		move_right(game);
	if ((keydata.key == MLX_KEY_ESCAPE) && keydata.action == MLX_PRESS)
	{
		ft_printf("forced exit\n");
		exit_success(game);
	}
}

int	upd_collected(int target_x, int target_y, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->to_collect)
	{
		if ((game->obj_img->instances[i].x == target_x * 64)
			&& (game->obj_img->instances[i].y == target_y * 64))
		{
			game->obj_img->instances[i].enabled = false;
			break ;
		}
		i++;
	}
	game->map[target_y][target_x] = '0';
	game->collected += 1;
	return (EXIT_SUCCESS);
}

int	move(int target_x, int target_y, t_game *game)
{
	if (game->map[target_y][target_x] == '1')
		return (EXIT_FAILURE);
	game->moves += 1;
	if (game->map[target_y][target_x] == 'C')
		return (upd_collected(target_x, target_y, game));
	if (game->map[target_y][target_x] == 'E'
		&& game->to_collect == game->collected)
	{
		ft_printf("moves: %i\n", game->moves);
		ft_printf("yay, moo deng has eaten all the rain boots\n");
		exit_success(game);
	}
	else if (game->map[target_y][target_x] == 'E')
		ft_printf("collect all the rain boots first!\n");
	return (EXIT_SUCCESS);
}
