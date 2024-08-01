/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:51:22 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/01 22:46:36 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		rendering(t_data *gdata);
void	load_xpm(t_data *gdata);
int		render_xpm(t_data *gdata);
void	display_xpm(char *line, t_data *gdata, int lines);
void	pl_location(t_data *gdata, int i, int lines);

/* The rendering func is responsible for loading the xpms by calling load_xpm.
Then it calls the real rendering function render_xpm which calls the display_xpm
function line by line. The display_xpm function iterates through the line for
the letter code in the map. */

int	rendering(t_data *gdata)
{
	load_xpm(gdata);
	render_xpm(gdata);
	return (0);
}

//load sprites (xpms)
void	load_xpm(t_data *gdata)
{
	gdata->sprites.wall = mlx_xpm_file_to_image(gdata->mlx_ptr,
			XPM_WALL, &gdata->spr_size, &gdata->spr_size);
	gdata->sprites.floo = mlx_xpm_file_to_image(gdata->mlx_ptr,
			XPM_FLOO, &gdata->spr_size, &gdata->spr_size);
	load_cow(gdata);
	gdata->sprites.exit = mlx_xpm_file_to_image(gdata->mlx_ptr,
			XPM_EXIT, &gdata->spr_size, &gdata->spr_size);
	load_player(gdata);
	load_snek(gdata);
	gdata->sprites.move = mlx_xpm_file_to_image(gdata->mlx_ptr,
			XPM_MOVE, &gdata->spr_size, &gdata->spr_size);
}

//just a func to call display_xpm line-by-line
int	render_xpm(t_data *gdata)
{
	int		i;

	i = 0;
	while (gdata->map_details.map[i])
	{
		display_xpm(gdata->map_details.map[i], gdata, i);
		i++;
	}
	player_spr(gdata);
	return (0);
}

//display sprites (xpm) 
void	display_xpm(char *line, t_data *gdata, int lines)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.wall, (i * gdata->spr_size), (lines * gdata->spr_size));
		else if (line[i] == '0')
			mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.floo, i * gdata->spr_size, (lines * gdata->spr_size));
		else if (line[i] == 'C')
			cow_animate(gdata, i, lines);
		else if (line[i] == 'E')
			mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.exit, (i * gdata->spr_size), (lines * gdata->spr_size));
		else if (line[i] == 'S')
			snek_animate(gdata, i, lines);
		else if (line[i] == 'P')
			pl_location(gdata, i, lines);
		i++;
	}
}

void	pl_location(t_data *gdata, int i, int lines)
{
	gdata->map_details.pl_pos_x = i;
	gdata->map_details.pl_pos_y = lines;
}
