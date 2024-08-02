/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:38:35 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/02 11:19:04 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check_elements(t_data *gdata);
void	gather_elements(t_data *gdata);
void	map_check_form(t_data *gdata);
void	check_rectangle(t_data *gdata);
void	check_walls(t_data *gdata);

//check the elements in map
void	map_check_elements(t_data *gdata)
{
	gather_elements(gdata);
	if (gdata->map_details.play_check != 1)
		quit_message(gdata, "Error\nWrong number of player.");
	if (gdata->map_details.exit_check != 1)
		quit_message(gdata, "Error\nWrong number of exit.");
	if (gdata->map_details.coll_check == 0)
		quit_message(gdata, "Error\nWrong number of collectibles.");
}

//gather elements and chekc for valid chars and store important ones
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
			if (!ft_strchr("CEP01S", gdata->map_details.map[i][j]))
				quit_message(gdata, "Error\nInvalid map element.");
			if (gdata->map_details.map[i][j] == 'P')
				gdata->map_details.play_check++;
			else if (gdata->map_details.map[i][j] == 'E')
				gdata->map_details.exit_check++;
			else if (gdata->map_details.map[i][j] == 'C')
				gdata->map_details.coll_check++;
			j++;
		}
		i++;
	}
}

//check if map is a rectangle and closed
void	map_check_form(t_data *gdata)
{
	check_rectangle(gdata);
	check_walls(gdata);
}

//rectangle check
void	check_rectangle(t_data *gdata)
{
	int		i;
	size_t	j;

	j = gdata->map_details.mapcols;
	i = 0;
	while (gdata->map_details.map[i])
	{
		if (j != ft_strlen(gdata->map_details.map[i]))
		{
			quit_message(gdata, "Error\nMap is not a rectangle.");
		}
		i++;
	}
}

//surrounding walls check
void	check_walls(t_data *gdata)
{
	int	i;

	i = 0;
	while (i < gdata->map_details.maprows)
	{
		if (gdata->map_details.map[i][0] != '1' || \
		gdata->map_details.map[i][gdata->map_details.mapcols - 1] != '1')
			quit_message(gdata, "Error\nMap is not closed.");
		i++;
	}
	i = 0;
	while (i < gdata->map_details.mapcols)
	{
		if (gdata->map_details.map[0][i] != '1' || \
		gdata->map_details.map[gdata->map_details.maprows - 1][i] != '1')
			quit_message(gdata, "Error\nMap is not closed.");
		i++;
	}
}
