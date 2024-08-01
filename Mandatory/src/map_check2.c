/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:40:13 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/01 17:04:03 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check_ff(t_data *gdata);
void	pl_pos(t_data *gdata, int i, int *player_col, int *player_row);
void	ex_pos(t_data *gdata);
void	flood_fill(t_data *gdata, int y, int x, int **visited);
int		validmove(t_data *gdata, int **visited, int y, int x);

void	map_check_ff(t_data *gdata)
{
	int	i;
	int	p_row;
	int	p_col;
	int	**visited;

	visited = ft_calloc(gdata->map_details.maprows, sizeof(int *));
	i = 0;
	while (i < gdata->map_details.maprows)
	{
		visited[i] = ft_calloc(gdata->map_details.mapcols, sizeof(int *));
		i++;
	}
	i = 0;
	while (gdata->map_details.map[i])
	{
		pl_pos(gdata, i, &p_col, &p_row);
		i++;
	}
	ex_pos(gdata);
	flood_fill(gdata, p_row, p_col, visited);
	i = visited[p_row][p_col] && visited[gdata->map_details.ex_pos_y][gdata->map_details.ex_pos_x];
	free_visited(visited, gdata);
	if (gdata->map_details.coll_ff != gdata->map_details.coll_check || !i)
		quit_message(gdata, "Error\nMap has no valid path.");
}

void	pl_pos(t_data *gdata, int i, int *player_col, int *player_row)
{
	int	j;

	j = 0;
	gdata->map_details.coll_ff = 0;
	gdata->map_details.coll_check = 0;
	while (gdata->map_details.map[i][j])
	{
		if (gdata->map_details.map[i][j] == 'P')
		{
			*player_row = i;
			*player_col = j;
			break ;
		}
		j++;
	}
}

void	ex_pos(t_data *gdata)
{
	int	j;
	int	i;

	i = 0;
	while (gdata->map_details.map[i])
	{
		j = 0;
		while (gdata->map_details.map[i][j])
		{
			if (gdata->map_details.map[i][j] == 'E')
			{
				gdata->map_details.ex_pos_y = i;
				gdata->map_details.ex_pos_x = j;
			}
			if (gdata->map_details.map[i][j] == 'C')
				gdata->map_details.coll_check += 1;
			j++;
		}
		i++;
	}
}

void	flood_fill(t_data *gdata, int y, int x, int **visited)
{
	if (!validmove(gdata, visited, y, x) || visited[y][x])
		return ;
	if (gdata->map_details.map[y][x] == 'C')
		gdata->map_details.coll_ff += 1;
	visited[y][x] = 1;
	flood_fill(gdata, y - 1, x, visited);
	flood_fill(gdata, y + 1, x, visited);
	flood_fill(gdata, y, x - 1, visited);
	flood_fill(gdata, y, x + 1, visited);
}

int	validmove(t_data *gdata, int **visited, int y, int x)
{
	return (gdata->map_details.map[y][x] != '1' && !visited[y][x]);
}


