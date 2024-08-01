/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:24:00 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/01 16:49:30 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_pos(t_data *gdata, int horizontal, int length);
void	update_spr(t_data *gdata);
void	tile_check(t_data *gdata);
void	player_spr(t_data *gdata);

//change player position according to keypress
void	update_pos(t_data *gdata, int horizontal, int length)
{
	if (horizontal == 1)
	{
		if (gdata->map_details.map[gdata->map_details.pl_pos_y]
			[gdata->map_details.pl_pos_x + length] == WALL)
			return ;
		update_spr(gdata);
		gdata->map_details.pl_pos_x += length;
	}
	else
	{
		if (gdata->map_details.map[gdata->map_details.pl_pos_y + length]
			[gdata->map_details.pl_pos_x] == WALL)
			return ;
		update_spr(gdata);
		gdata->map_details.pl_pos_y += length;
	}
	tile_check(gdata);
	player_spr(gdata);
}

//refresh sprite after player leaves the tile
void	update_spr(t_data *gdata)
{
	if (gdata->map_details.map[gdata->map_details.pl_pos_y]
		[gdata->map_details.pl_pos_x] == EXIT)
	{
		mlx_put_image_to_window(
			gdata->mlx_ptr, gdata->win_ptr, gdata->sprites.exit,
			SPR_SIZE * gdata->map_details.pl_pos_x,
			SPR_SIZE * gdata->map_details.pl_pos_y);
	}
	else
		mlx_put_image_to_window(
			gdata->mlx_ptr, gdata->win_ptr, gdata->sprites.floo,
			SPR_SIZE * gdata->map_details.pl_pos_x,
			SPR_SIZE * gdata->map_details.pl_pos_y);
}

//check if player is on collectible or exit tile
void	tile_check(t_data *gdata)
{
	if (gdata->map_details.map[gdata->map_details.pl_pos_y]
		[gdata->map_details.pl_pos_x] == COLL)
	{
		gdata->map_details.map[gdata->map_details.pl_pos_y]
		[gdata->map_details.pl_pos_x] = FLOO;
		gdata->map_details.coll_check -= 1;
		return ;
	}
	if (gdata->map_details.map[gdata->map_details.pl_pos_y]
		[gdata->map_details.pl_pos_x] == EXIT
		&& gdata->map_details.coll_check == 0)
	{
		ft_printf("Win!\nHad lunch and now at home!!\n");
		on_quit(gdata);
	}
}

//display player sprite and movement
void	player_spr(t_data *gdata)
{
	char	*moves;
	char	*movement;

	mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, gdata->sprites.play,
		SPR_SIZE * gdata->map_details.pl_pos_x, \
		SPR_SIZE * gdata->map_details.pl_pos_y);
	mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr,
		gdata->sprites.move, 0, 0);
	gdata->movement += 1;
	moves = ft_itoa(gdata->movement - 1);
	movement = "Moves:";
	mlx_string_put(gdata->mlx_ptr, gdata->win_ptr, 15, 25, 1, movement);
	mlx_string_put(gdata->mlx_ptr, gdata->win_ptr, 30, 40, 1, moves);
	free(moves);
}
