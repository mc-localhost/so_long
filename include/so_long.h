/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:10:30 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/12/12 12:31:04 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_game
{
	mlx_t		*mlx;
	char		*map_to_split;
	char		**map;
	char		**map_copy;
	int			rows;
	int			cols;
	int			moves;
	int			collected;
	int			to_collect;
	t_pos		hero;
	mlx_image_t	*hero_img;
	mlx_image_t	*obj_img;
	mlx_image_t	*tile_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*exit_img;
}				t_game;

// MAIN
int				init_game(t_game *game, char *path);
void			render_ifs(t_game *game, char c, int x, int y);
void			render_game(t_game *game);

// IMAGES
void			create_img(char *address, mlx_image_t **x_img, t_game *game);
void			create_imgs(t_game *game);

// MOVES
void			move_hero_hook(mlx_key_data_t keydata, void *param);
int				move(int target_x, int target_y, t_game *game);
int				upd_collected(int target_x, int target_y, t_game *game);

// MOVES UP,DOWN,LEFT,RIGHT
void			move_up(t_game *game);
void			move_down(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);

// UTILS
// void			exit_success(t_game *game);
void			exit_success(void *param);
void			error(void *param);
int				error_message(char *str);
void			print_2d(char **arr);

// FREE
void			ft_free_split(char **splits);
void			free_game(t_game *game);
void			delete_images(t_game *game);

// MAP READ
int				ber_file(char *map_path);
int				file_size_with_char_check(char *map_path);
char			*read_map(char *map_path);

// MAP CHECK
int				check_map(t_game *game);
int				line_len_check(t_game *game);
int				empty_lines_check(t_game *game, int n_count);
int				borders_check(t_game *game);
int				chars_check(t_game *game, int c_count, int p_count,
					int e_count);

int				flood_fill(t_game *game, int c_e_counter);
void			fill(char **map, int cols, int rows, t_pos begin);

#endif