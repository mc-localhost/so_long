/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:18:04 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/12/11 14:19:28 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	create_img(char *address, mlx_image_t **x_img, t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(address);
	if (!texture)
		error(game);
	*x_img = mlx_texture_to_image(game->mlx, texture);
	if (!(*x_img))
		error(game);
	mlx_delete_texture(texture);
}

void	create_imgs(t_game	*game)
{
	create_img("png/hero.png", &game->hero_img, game);
	create_img("png/obj.png", &game->obj_img, game);
	create_img("png/tile.png", &game->tile_img, game);
	create_img("png/wall.png", &game->wall_img, game);
	create_img("png/exit.png", &game->exit_img, game);
}
