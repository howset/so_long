/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:48:55 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/01 19:08:58 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_load(char *ber_file, t_data *gdata);
int		read_ber(char *ber_file);
int		fill_map(char *ber_file, t_data *gdata);

/* map_load calls read_ber to get the total lines in the map file and stores it
in gdata->map_details.maprows and allocates the corresponding size for the
array. Then it calls fill_map to fill the array with the map data, and counts
the columns (and store it in gdata->map_details.mapcols). */

void	map_load(char *ber_file, t_data *gdata)
{
	gdata->map_details.maprows = read_ber(ber_file);
	gdata->map_details.map = malloc((gdata->map_details.maprows + 1) \
	* sizeof(char *));
	if (!gdata->map_details.map)
		quit_message(gdata, "Error\nMap allocation failed.");
	gdata->map_details.mapcols = fill_map(ber_file, gdata);
}

//open the map file and counts the lines in the file.
int	read_ber(char *ber_file)
{
	int		file;
	int		rows;
	char	*line;

	rows = 0;
	file = open(ber_file, O_RDONLY);
	if (file == -1)
		quit_message(NULL, "Error\nMap opening failed.");
	line = get_next_line(file);
	if (!line)
		quit_message(NULL, "Error\nEmpty map file.");
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(file);
	}
	close(file);
	free(line);
	if (rows < 3)
		quit_message(NULL, "Error\nIncompatible map. (rows)");
	return (rows);
}

//fill the map array with the map data.
int	fill_map(char *ber_file, t_data *gdata)
{
	int	file;
	int	i;
	int	cols;

	file = open(ber_file, O_RDONLY);
	if (file == -1)
		quit_message(gdata, "Error\nMap opening failed.");
	i = 0;
	while (i < gdata->map_details.maprows)
		gdata->map_details.map[i++] = get_next_line(file);
	gdata->map_details.map[i] = NULL;
	close (file);
	i = 0;
	while (i < (gdata->map_details.maprows - 1))
	{
		gdata->map_details.map[i] = \
			remove_trailing(gdata->map_details.map[i], "\n");
		i++;
	}
	cols = ft_strlen(gdata->map_details.map[0]);
	if (cols < 3)
		quit_message(gdata, "Error\nIncompatible map (cols).");
	return (cols);
}
