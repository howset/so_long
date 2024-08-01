/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_load_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:48:37 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/01 21:01:03 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_snek(t_data *gdata)
{
	gdata->sprites.snek0 = mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_SNEK_0, \
	&gdata->spr_size, &gdata->spr_size);
	gdata->sprites.snek1 = mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_SNEK_1, \
	&gdata->spr_size, &gdata->spr_size);
	gdata->sprites.snek2 = mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_SNEK_2, \
	&gdata->spr_size, &gdata->spr_size);
	gdata->sprites.snek3 = mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_SNEK_3, \
	&gdata->spr_size, &gdata->spr_size);
}

void	load_cow(t_data *gdata)
{
	gdata->sprites.coll0 = mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_COLL_0, \
	&gdata->spr_size, &gdata->spr_size);
	gdata->sprites.coll1 = mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_COLL_1, \
	&gdata->spr_size, &gdata->spr_size);
}

void	load_player(t_data *gdata)
{
	gdata->sprites.play0 = \
	mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_PLAY_DOWN_0, \
	&gdata->spr_size, &gdata->spr_size);
	gdata->sprites.play1 = \
	mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_PLAY_DOWN_1, \
	&gdata->spr_size, &gdata->spr_size);
	gdata->sprites.play2 = \
	mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_PLAY_DOWN_2, \
	&gdata->spr_size, &gdata->spr_size);
	gdata->sprites.play3 = \
	mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_PLAY_DOWN_3, \
	&gdata->spr_size, &gdata->spr_size);
}
