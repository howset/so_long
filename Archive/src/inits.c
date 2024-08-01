/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:14:14 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/07/29 15:57:55 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_assets(t_data data)
{
	data.sprites.wall = mlx_xpm_file_to_image(data.mlx_ptr, \
	XPM_WALL, &data.width, &data.height);
	data.sprites.floo = mlx_xpm_file_to_image(data.mlx_ptr, \
	XPM_FLOO, &data.width, &data.height);
	data.sprites.coll = mlx_xpm_file_to_image(data.mlx_ptr, \
	XPM_COLL_0, &data.width, &data.height);
	data.sprites.exit = mlx_xpm_file_to_image(data.mlx_ptr, \
	XPM_EXIT, &data.width, &data.height);
	data.sprites.play = mlx_xpm_file_to_image(data.mlx_ptr, \
	XPM_PLAY_DOWN_0, &data.width, &data.height);
	return (0);
}

void	init_assets(t_data data)
{
	data.height = SPR_HEIGHT;
	data.width = SPR_WIDTH;
	/* data.current_frame = 0;
	data.player.player_idle_right_1 = mlx_xpm_file_to_image(game.mlx, \
	"assets/player_idle_right_1.xpm", &game.width, &game.height); */
	if (load_assets(data) == 1)
		write(1, "failed to open the image\n", 25);
}

t_data	initialize(t_data *data)
{
	data.win_ptr = NULL;
	data.map.map = NULL;
	data.map.maprows = 0;
	data.map.mapcols = 0;
	data.sprites.wall = NULL;
	data.sprites.floo = NULL;
	data.sprites.coll = NULL;
	data.sprites.exit = NULL;
	data.sprites.play = NULL;
	data.sprites.snek = NULL;
	data.width = 0;
	data.height = 0;
	init_assets(data);
	return(data);
}
