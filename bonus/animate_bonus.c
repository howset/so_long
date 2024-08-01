/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:12:39 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/01 19:47:00 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	snek_animate(t_data *gdata, int x, int y)
{
	if (gdata->frame == 0)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.snek0, 0 + x * 64, 0 + (y * 64));
	else if (gdata->frame == 1)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.snek1, 0 + x * 64, 0 + (y * 64));
	else if (gdata->frame == 2)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.snek2, 0 + x * 64, 0 + (y * 64));
	else if (gdata->frame == 3)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.snek3, 0 + x * 64, 0 + (y * 64));
}

/* void	pll_animate(t_data *gdata, int w, int h)
{
	if (gdata->current_frame == 0 || gdata->current_frame == 1)
		mlx_put_image_to_window(gdata->mlx, gdata->window, \
		gdata->player.player_idle_left_1, 0 + w * 32, 0 + (h * 32));
	else if (gdata->current_frame == 2 || gdata->current_frame == 3)
		mlx_put_image_to_window(gdata->mlx, gdata->window, \
		gdata->player.player_idle_left_2, 0 + w * 32, 0 + (h * 32));
}

void	plr_animate(t_data *gdata, int w, int h)
{
	if (gdata->current_frame == 0 || gdata->current_frame == 1)
		mlx_put_image_to_window(gdata->mlx, gdata->window, \
		gdata->player.player_idle_right_1, 0 + w * 32, 0 + (h * 32));
	else if (gdata->current_frame == 2 || gdata->current_frame == 3)
		mlx_put_image_to_window(gdata->mlx, gdata->window, \
		gdata->player.player_idle_right_2, 0 + w * 32, 0 + (h * 32));
}

void	plt_animate(t_data *gdata, int w, int h)
{
	if (gdata->current_frame == 0 || gdata->current_frame == 1)
		mlx_put_image_to_window(gdata->mlx, gdata->window, \
		gdata->player.player_idle_top_1, 0 + w * 32, 0 + (h * 32));
	else if (gdata->current_frame == 2 || gdata->current_frame == 3)
		mlx_put_image_to_window(gdata->mlx, gdata->window, \
		gdata->player.player_idle_top_2, 0 + w * 32, 0 + (h * 32));
}

void	pld_animate(t_data *gdata, int w, int h)
{
	if (gdata->current_frame == 0 || gdata->current_frame == 1)
		mlx_put_image_to_window(gdata->mlx, gdata->window, \
		gdata->player.player_idle_down_1, 0 + w * 32, 0 + (h * 32));
	else if (gdata->current_frame == 2 || gdata->current_frame == 3)
		mlx_put_image_to_window(gdata->mlx, gdata->window, \
		gdata->player.player_idle_down_2, 0 + w * 32, 0 + (h * 32));
} */