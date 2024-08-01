/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:48:55 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/07/31 14:17:24 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_ber(char *ber_file);
int	fill_map(char *ber_file, t_data *gdata);

/* map_load calls read_ber to get the total lines in the map file and stores it
in gdata->map_details.maprows and allocates the corresponding size for the
array. Then it calls fill_map to fill the array with the map data, and counts
the columns (and store it in gdata->map_details.mapcols). */

void	map_load(char *ber_file, t_data *gdata)
{
	gdata->map_details.maprows = read_ber(ber_file);
	gdata->map_details.map = malloc((gdata->map_details.maprows + 1) * sizeof(char *));
	if (!gdata->map_details.map)
		quit_message(gdata, "Map allocation failed.");
	gdata->map_details.mapcols = fill_map(ber_file, gdata);
}

int	read_ber(char *ber_file)
{
	int		file;
	int		rows;
	char	*line;

	rows = 0;
	file = open(ber_file, O_RDONLY);
	if (file == -1)
		quit_message(NULL, "Map opening failed.");
	line = get_next_line(file);
	if (!line)
		quit_message(NULL, "Empty map file.");
	while (line)
	{
		free(line);
		line = get_next_line(file);
		rows++;
	}
	close(file);
	free(line);
	if (rows < 3)
		quit_message(NULL, "Incompatible map.");
	return (rows);
}

int	fill_map(char *ber_file, t_data *gdata)
{
	int	file;
	int	i;
	int	cols;

	file = open(ber_file, O_RDONLY);
	if (file == -1)
		quit_message(gdata, "Map opening failed.");
	i = 0;
	while (i < gdata->map_details.maprows)
		gdata->map_details.map[i++] = get_next_line(file);
	gdata->map_details.map[i] = NULL;
	close(file);
	cols = ft_strlen(gdata->map_details.map[i-1]);
	return (cols);
}
