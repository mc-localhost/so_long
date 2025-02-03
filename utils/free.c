/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:17:58 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/12/11 14:20:51 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_split(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
		free(splits[i++]);
	free(splits);
}

void	free_game(t_game *game)
{
	if (game->map_to_split)
		free(game->map_to_split);
	if (game->map)
		ft_free_split(game->map);
	if (game->map_copy)
		ft_free_split(game->map_copy);
}

void	delete_images(t_game *game)
{
	if (game->hero_img)
		mlx_delete_image(game->mlx, game->hero_img);
	if (game->obj_img)
		mlx_delete_image(game->mlx, game->obj_img);
	if (game->tile_img)
		mlx_delete_image(game->mlx, game->tile_img);
	if (game->wall_img)
		mlx_delete_image(game->mlx, game->wall_img);
	if (game->exit_img)
		mlx_delete_image(game->mlx, game->exit_img);
}
