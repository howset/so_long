/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:38:35 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/07/31 15:04:58 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// argument checks
void	check_args(int argc, char *argv)
{
	int		fd;
	int		i;
	int		j;
	
	if (argc != 2)
		quit_message(NULL, "Invalid number of arguments.");
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		quit_message(NULL, "File does not exist.");
	close(fd);
	i = ft_strlen(argv) - 4;
	j = ft_strncmp(".ber", &argv[i], 4);
	if ( j != 0)
		quit_message(NULL, "Only accepts .ber files.");
}

void	gather_elements(t_data *gdata)
{
	int	i;
	int	j;

	i = 0;
	while (i < gdata->map_details.maprows)
	{
		j = 0;
		while (j < gdata->map_details.mapcols)
		{
			if (gdata->map_details.map[i][j] == PLAY)
				gdata->map_details.play_check += 1;
			else if (gdata->map_details.map[i][j] == EXIT)
				gdata->map_details.exit_check += 1;
			else if (gdata->map_details.map[i][j] == COLL)
				gdata->map_details.coll_check += 1;
			j++;
		}
		i++;
	}
}

void	check_elements(t_data *gdata)
{
	gather_elements(gdata);
	if (gdata->map_details.play_check != 1)
		quit_message(gdata, "Wrong number of player.");
	if (gdata->map_details.exit_check != 1)
		quit_message(gdata, "Wrong number of exit.");
	if (gdata->map_details.coll_check == 0)
		quit_message(gdata, "Wrong number of collectibles.");
}