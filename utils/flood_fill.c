/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:17:52 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/12/11 14:20:48 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
flood fill will check if there is a way to go through the map,
collect everything and exit
*/
void	fill(char **map, int cols, int rows, t_pos begin)
{
	if (begin.x < 0 || begin.y < 0 || begin.x >= cols || begin.y >= rows
		|| map[begin.y][begin.x] == '1' || map[begin.y][begin.x] == 'X')
		return ;
	map[begin.y][begin.x] = 'X';
	fill(map, cols, rows, (t_pos){begin.x + 1, begin.y});
	fill(map, cols, rows, (t_pos){begin.x, begin.y + 1});
	fill(map, cols, rows, (t_pos){begin.x - 1, begin.y});
	fill(map, cols, rows, (t_pos){begin.x, begin.y - 1});
}

int	flood_fill(t_game *game, int c_e_counter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	fill(game->map_copy, game->cols, game->rows, game->hero);
	while (i < game->rows)
	{
		while (j < game->cols)
		{
			if (game->map_copy[i][j] == 'C' || game->map_copy[i][j] == 'E')
			{
				c_e_counter++;
				break ;
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (c_e_counter > 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
