/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:24:00 by nnuno-ca          #+#    #+#             */
/*   Updated: 2024/07/31 15:03:42 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_spr(t_data *gdata)
{
	char	*moves_str;

	gdata->movement += 1;
	mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, gdata->sprites.play,
		SPR_SIZE * gdata->map_details.p_pos_x, SPR_SIZE * gdata->map_details.p_pos_y);
/* 	mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr,
		gdata->sprites.wall, 0, 0); */
	moves_str = ft_itoa(gdata->movement - 1);
	//mlx_string_put(gdata->mlx_ptr, gdata->win_ptr, 67, 67, 1, moves_str);
	//ft_printf("moves_str: %s\n", moves_str);
	ft_printf("gdata->map_details.coll: %d\n", gdata->map_details.coll_check);
	ft_printf("gdata->map_details.exit: %d\n", gdata->map_details.exit_check);
	ft_printf("gdata->map_details.play: %d\n", gdata->map_details.play_check);
	free(moves_str);
}

static void	which_tile(t_data *gdata)
{
	if (gdata->map_details.map[gdata->map_details.p_pos_y]
		[gdata->map_details.p_pos_x] == COLL)
	{
		gdata->map_details.map[gdata->map_details.p_pos_y]
		[gdata->map_details.p_pos_x] = FLOO;
		gdata->map_details.coll_check -= 1;
		return ;
	}
	if (gdata->map_details.map[gdata->map_details.p_pos_y][gdata->map_details.p_pos_x] == EXIT
		&& gdata->map_details.coll_check == 0)
	{
		ft_printf("WIN!!\n");
		on_quit(gdata);
	}
}

/* Overloads the player tile that is left behind when the player moves */
static void	update_sprite(t_data *gdata)
{
	if (gdata->map_details.map[gdata->map_details.p_pos_y]
		[gdata->map_details.p_pos_x] == EXIT)
	{
		mlx_put_image_to_window(
			gdata->mlx_ptr, gdata->win_ptr, gdata->sprites.exit,
			SPR_SIZE * gdata->map_details.p_pos_x,
			SPR_SIZE * gdata->map_details.p_pos_y);
	}
	else
		mlx_put_image_to_window(
			gdata->mlx_ptr, gdata->win_ptr, gdata->sprites.floo,
			SPR_SIZE * gdata->map_details.p_pos_x,
			SPR_SIZE * gdata->map_details.p_pos_y);
}

void	update_player_pos(t_data *gdata, int horizontal, int length)
{
	if (horizontal == 1)
	{
		if (gdata->map_details.map[gdata->map_details.p_pos_y]
			[gdata->map_details.p_pos_x + length] == WALL)
			return ;
		update_sprite(gdata);
		gdata->map_details.p_pos_x += length;
	}
	else
	{
		if (gdata->map_details.map[gdata->map_details.p_pos_y + length]
			[gdata->map_details.p_pos_x] == WALL)
			return ;
		update_sprite(gdata);
		gdata->map_details.p_pos_y += length;
	}
	which_tile(gdata);
	player_spr(gdata);
}
