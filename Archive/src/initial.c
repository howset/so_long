/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:18:33 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/07/31 15:00:43 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* initialize_gdata initializes values in the struct gdata.
initialize_mlx starts the mlx and creates a window. */

t_data	initialize_gdata(t_data *gdata)
{
	gdata->map_details.map = NULL;
	gdata->map_details.maprows = 0;
	gdata->map_details.mapcols = 0;
	gdata->map_details.coll_check = 0;
	gdata->map_details.exit_check = 0;
	gdata->map_details.play_check = 0;
	gdata->sprites.wall = NULL;
	gdata->sprites.floo = NULL;
	gdata->sprites.coll = NULL;
	gdata->sprites.exit = NULL;
	gdata->sprites.play = NULL;
	gdata->sprites.snek = NULL;
	gdata->spr_size = SPR_SIZE;
	gdata->movement = 0;
	return (*gdata);
}

void	initialize_mlx(t_data *gdata)
{
	gdata->mlx_ptr = mlx_init();
	if (gdata->mlx_ptr == NULL)
		quit_message(gdata, "Mlx initialization failed.");
	gdata->win_ptr = mlx_new_window(gdata->mlx_ptr,
			gdata->map_details.mapcols * SPR_SIZE, gdata->map_details.maprows * SPR_SIZE,
			"so_long");
	if (gdata->win_ptr == NULL)
		quit_message(gdata, "Mlx new window failed.");
}

