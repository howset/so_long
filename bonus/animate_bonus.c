/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:12:39 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/01 20:44:54 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	snek_animate(t_data *gdata, int x, int y)
{
	if (gdata->frame == 0)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.snek0, x * 64, y * 64);
	else if (gdata->frame == 1)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.snek1, x * 64, y * 64);
	else if (gdata->frame == 2)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.snek2, x * 64, y * 64);
	else if (gdata->frame == 3)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.snek3, x * 64, y * 64);
}

void	cow_animate(t_data *gdata, int x, int y)
{
	if (gdata->frame == 0)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.coll0, x * 64, y * 64);
	else if (gdata->frame == 1)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.coll1, x * 64, y * 64);
	else if (gdata->frame == 2)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.coll0, x * 64, y * 64);
	else if (gdata->frame == 3)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.coll1, x * 64, y * 64);
}

void	player_animate(t_data *gdata, int x, int y)
{
	if (gdata->frame == 0)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.play0, x * 64, y * 64);
	else if (gdata->frame == 1)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.play1, x * 64, y * 64);
	else if (gdata->frame == 2)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.play2, x * 64, y * 64);
	else if (gdata->frame == 3)
		mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
		gdata->sprites.play3, x * 64, y * 64);
}
