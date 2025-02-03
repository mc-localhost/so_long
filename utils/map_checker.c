/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:43:45 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/12/11 14:20:56 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
map checker is checking if the map read from .ber file is valid,
excluding the character check for 1,0,C,E,P which is performed on the first read
in map_reader.c

map checker is also partially used to fill t_game with data
	- game->cols
	- game->rows
	- game->to_collect
	- game->hero.x & game->hero.y
*/

int	check_map(t_game *game)
{
	if (line_len_check(game) == EXIT_FAILURE)
		return (error_message("Error\nnon-rectangular map\n"));
	else if (empty_lines_check(game, 0) == EXIT_FAILURE)
		return (error_message("Error\nmap has empty lines\n"));
	else if (borders_check(game) == EXIT_FAILURE)
		return (error_message("Error\nmap isn't surrounded by walls\n"));
	else if (chars_check(game, 0, 0, 0) == EXIT_FAILURE)
		return (error_message("Error\ncheck there's >=1'C', 1'E', 1'P'\n"));
	else if (flood_fill(game, 0) == EXIT_FAILURE)
		return (error_message("Error\nno valid path in the map"));
	return (EXIT_SUCCESS);
}

// every line has the same length
int	line_len_check(t_game *game)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != len)
			return (EXIT_FAILURE);
		i++;
	}
	game->cols = (int)len;
	game->rows = i;
	return (EXIT_SUCCESS);
}

// map is surrounded by walls (1)
int	borders_check(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		if ((game->map[i][0] != '1') || (game->map[i][game->cols - 1] != '1'))
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < game->cols)
	{
		if ((game->map[0][i] != '1') || (game->map[game->rows - 1][i] != '1'))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

// there are collectables, only one P, and only one E
int	chars_check(t_game *game, int c_count, int p_count, int e_count)
{
	int	i;

	i = 0;
	while (game->map_to_split[i])
	{
		if (game->map_to_split[i] == 'C')
			c_count++;
		else if (game->map_to_split[i] == 'P')
		{
			game->hero.x = i % (game->cols + 1);
			game->hero.y = i / (game->cols + 1);
			p_count++;
		}
		else if (game->map_to_split[i] == 'E')
			e_count++;
		i++;
	}
	if (p_count != 1 || e_count != 1 || c_count < 1)
		return (EXIT_FAILURE);
	game->to_collect = c_count;
	return (EXIT_SUCCESS);
}

// there are no empty lines in map file
// this check isn't crucial, thus inefficient and removable
int	empty_lines_check(t_game *game, int n_count)
{
	int	i;

	i = 0;
	while (game->map_to_split[i])
	{
		if (game->map_to_split[i] == '\n')
			n_count++;
		i++;
	}
	if (n_count != game->rows - 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
