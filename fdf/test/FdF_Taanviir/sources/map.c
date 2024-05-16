/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:30 by tanas             #+#    #+#             */
/*   Updated: 2023/02/28 20:02:26 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// function name is self-explanatory
static t_map	get_height_width(char *file)
{
	int		fd;
	char	*line;
	char	**vals;
	t_map	map;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	vals = ft_split(line, ' ');
	map.width = 0;
	while (vals[map.width])
		map.width++;
	free(line);
	ft_free_double((void **) vals);
	map.height = 0;
	while (line)
	{
		map.height++;
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
	return (map);
}

// get_values gets the z values for one line
static int	*get_values(char **values_str, t_map map, int y)
{
	int		*z_values;
	int		x;

	map.colours[y] = extract_colours(values_str, map);
	z_values = (int *) malloc(sizeof(int) * map.width);
	if (!z_values)
		return (NULL);
	x = 0;
	while (x < map.width)
	{
		z_values[x] = ft_atoi(values_str[x]);
		x++;
	}
	ft_free_double((void **) values_str);
	return (z_values);
}

// fills up the map with the required z values which can be then
// accessed using the corresponding x, y values
t_map	get_map(char *file)
{
	int		fd;
	char	*line;
	int		y;
	t_map	map;

	map = get_height_width(file);
	map.z_values = (int **) malloc(sizeof(int *) * (map.height + 1));
	if (!map.z_values)
		exit(2);
	map.colours = (int **) malloc(sizeof(int *) * (map.height + 1));
	if (!map.z_values)
		exit(3);
	y = 0;
	fd = open(file, O_RDONLY);
	while (y < map.height)
	{
		line = get_next_line(fd);
		map.z_values[y] = get_values(ft_split(line, ' '), map, y);
		free(line);
		y++;
	}
	map.colours[y] = NULL;
	map.z_values[y] = NULL;
	free(get_next_line(fd));
    close(fd);
	return (map);
}
