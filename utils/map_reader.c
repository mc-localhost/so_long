/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:18:21 by vvasiuko          #+#    #+#             */
/*   Updated: 2024/12/11 14:23:09 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ber_file(char *map_path)
{
	size_t	len;

	len = ft_strlen(map_path);
	if (len < 4)
		return (EXIT_FAILURE);
	return (ft_strncmp(map_path + len - 4, ".ber", 4));
}

int	file_size_with_char_check(char *map_path)
{
	int		fd;
	char	buffer[1];
	int		bytes_read;

	bytes_read = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, buffer, 1) == 1)
	{
		if (!ft_strchr("10CEP\n", *buffer))
		{
			printf("Error\nunrecognised char in map: %c\n", *buffer);
			return (close (fd), 0);
		}
		bytes_read++;
	}
	return (close (fd), bytes_read);
}

char	*read_map(char *map_path)
{
	int		fd;
	int		bytes_read;
	char	*str_map;

	bytes_read = file_size_with_char_check(map_path);
	if (bytes_read < 15)
		return (NULL);
	str_map = (char *)malloc(sizeof(char) * (bytes_read + 1));
	if (!str_map)
		return (NULL);
	fd = open(map_path, O_RDONLY);
	read(fd, str_map, bytes_read);
	str_map[bytes_read] = '\0';
	return (close (fd), str_map);
}
