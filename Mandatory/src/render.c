/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:51:22 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/01 16:50:58 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_xpm(t_data *gdata);
void	display_xpm(char *line, t_data *gdata, int lines);
int		render_xpm(t_data *gdata);

/* The rendering func is responsible for loading the xpms by calling load_xpm.
Then it calls the real rendering function render_xpm which calls the display_xpm
function line by line. The display_xpm function iterates through the line for
the letter code in the map. */

void	rendering(t_data *gdata)
{
	load_xpm(gdata);
	render_xpm(gdata);
}

//load sprites (xpms)
void	load_xpm(t_data *gdata)
{
	gdata->sprites.wall = mlx_xpm_file_to_image(gdata->mlx_ptr,
			XPM_WALL, &gdata->spr_size, &gdata->spr_size);
	gdata->sprites.floo = mlx_xpm_file_to_image(gdata->mlx_ptr,
			XPM_FLOO, &gdata->spr_size, &gdata->spr_size);
	gdata->sprites.coll = mlx_xpm_file_to_image(gdata->mlx_ptr,
			XPM_COLL_0, &gdata->spr_size, &gdata->spr_size);
	gdata->sprites.exit = mlx_xpm_file_to_image(gdata->mlx_ptr,
			XPM_EXIT, &gdata->spr_size, &gdata->spr_size);
	gdata->sprites.play = mlx_xpm_file_to_image(gdata->mlx_ptr,
			XPM_PLAY_DOWN_0, &gdata->spr_size, &gdata->spr_size);
	gdata->sprites.snek = mlx_xpm_file_to_image(gdata->mlx_ptr,
			XPM_SNEK_0, &gdata->spr_size, &gdata->spr_size);
	gdata->sprites.move = mlx_xpm_file_to_image(gdata->mlx_ptr,
			XPM_MOVE, &gdata->spr_size, &gdata->spr_size);
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
			mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.coll, (i * gdata->spr_size), (lines * gdata->spr_size));
		else if (line[i] == 'E')
			mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.exit, (i * gdata->spr_size), (lines * gdata->spr_size));
		else if (line[i] == 'S')
			mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.snek, (i * gdata->spr_size), (lines * gdata->spr_size));
		else if (line[i] == 'P')
		{
			gdata->map_details.pl_pos_x = i;
			gdata->map_details.pl_pos_y = lines;
		}
		i++;
	}
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
