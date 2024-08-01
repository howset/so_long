/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:51:20 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/07/29 15:12:23 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_maplines(char *line, t_data *data, int lines)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->sprites.wall, 0 + i * 64, 0 + (lines * 64));
		else if (line[i] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->sprites.floo, 0 + i * 64, 0 + (lines * 64));
		else if (line[i] == 'C')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->sprites.coll, 0 + i * 64, 0 + (lines * 64));
		else if (line[i] == 'E')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->sprites.exit, 0 + i * 64, 0 + (lines * 64));
		else if (line[i] == 'P')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->sprites.play, 0 + i * 64, 0 + (lines * 64));
		//else if (line[i] == 'P')
		//	put_player(game, i, index);
		i++;
	}
}

int	display_mapfull(t_data *data)
{
	int		i;

	i = 0;
	//game->score = 0;
	while (data->map.map[i] != NULL)
	{
		display_maplines(data->map.map[i], data, i);
		i++;
	}
	return (0);
}

void	populate_map(int linecount, char *map, t_data *data)
{
	int	file;
	int	i;

	file = open(map, O_RDONLY);
	//game->moves = 0;
	//game->player_position = 0;
	data->map.map = malloc(sizeof(char *) * (linecount + 1));
	for (i = 0; i <= linecount; i++) {
		data->map.map[i] = NULL; // Initialize all pointers to NULL
	}
	data->map.map[0] = get_next_line(file);
	i = 0;
	while (i < linecount)
	{
		data->map.map[i] = get_next_line(file);
		i++;
	}
	i = 0;
	while (data->map.map[0][i])
		i++;
	data->map.mapcols = i+1;
	data->map.maprows = linecount;
	//if (check_map(map, game) == 1)
	//	exit(EXIT_FAILURE);
	//if (valid_path(game) == 1)
	//{
	//	free_map(game);
	//	write(1, "Error\nNo valid path\n", 20);
	//	exit(EXIT_FAILURE);
	//}
	close(file);
}

int	read_ber(char *map, t_data *data)
{
	int		file;
	int		linecount;
	char	*line;

	linecount = 0;
	file = open(map, O_RDONLY);
	if (file == -1)
	{
		write(1, "Error\nMap does not exist\n", 25);
		return (1);
	}
	line = get_next_line(file);
	if (line == NULL)
		exit(EXIT_FAILURE);
	while (line)
	{
		free(line);
		line = get_next_line(file);
		linecount++;
	}
	close(file);
	populate_map(linecount, map, data);
	free(line);
	return (0);
}