/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_load_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetya <hsetya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:48:37 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/01 23:10:06 by hsetya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//load snek sprites
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

//load snek sprites
void	load_cow(t_data *gdata)
{
	gdata->sprites.coll0 = mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_COLL_0, \
	&gdata->spr_size, &gdata->spr_size);
	gdata->sprites.coll1 = mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_COLL_1, \
	&gdata->spr_size, &gdata->spr_size);
}

//load snek sprites
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
