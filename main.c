/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:43:01 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/12/12 12:48:19 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

// void	leaks(void)
// {
// 	system("leaks so_long");
// }

int	init_game(t_game *game, char *path)
{
	if (ber_file(path) != 0)
		return (error_message("Error\nwrong file extension: must be .ber\n"));
	game->map_to_split = read_map(path);
	if (!game->map_to_split)
		return (error_message("Error\ncould not read map\n"));
	game->map = ft_split(game->map_to_split, '\n');
	game->map_copy = ft_split(game->map_to_split, '\n');
	if (!game->map || !game->map_copy)
	{
		free_game(game);
		return (error_message("Error\ncould not split map\n"));
	}
	if (check_map(game) == EXIT_FAILURE)
	{
		free_game(game);
		return (EXIT_FAILURE);
	}
	game->moves = 0;
	game->collected = 0;
	return (EXIT_SUCCESS);
}

void	render_ifs(t_game *game, char c, int x, int y)
{
	if (mlx_image_to_window(game->mlx, game->tile_img, x, y) < 0)
		error(game);
	if (c == '1')
	{
		if (mlx_image_to_window(game->mlx, game->wall_img, x, y) < 0)
			error(game);
	}
	else if (c == 'C')
	{
		if (mlx_image_to_window(game->mlx, game->obj_img, x, y) < 0)
			error(game);
	}
	else if (c == 'E')
	{
		if (mlx_image_to_window(game->mlx, game->exit_img, x, y) < 0)
			error(game);
	}
}

void	render_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->mlx = mlx_init(game->cols * 64, game->rows * 64, "so_long", false);
	if (!game->mlx)
		error(game);
	create_imgs(game);
	while (i < game->rows)
	{
		while (j < game->cols)
		{
			render_ifs(game, game->map[i][j], j * 64, i * 64);
			j++;
		}
		i++;
		j = 0;
	}
	if (mlx_image_to_window(game->mlx, game->hero_img,
			64 * game->hero.x, 64 * game->hero.y) < 0)
		error(game);
}

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (error_message("Error\nput .ber map path after ./so_long\n"));
	if (init_game(&game, argv[1]) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	render_game(&game);
	mlx_key_hook(game.mlx, move_hero_hook, &game);
	mlx_close_hook(game.mlx, exit_success, &game);
	mlx_loop(game.mlx);
	exit_success(&game);
	return (EXIT_SUCCESS);
}

	// atexit(leaks);