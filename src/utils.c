/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:22:37 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/07/26 18:47:35 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}

/* void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
} */

int	load_assets(t_data *data)
{
	data->sprites.wall = mlx_xpm_file_to_image(data->mlx_ptr, \
	XPM_WALL, &data->width, &data->height);
	data->sprites.floo = mlx_xpm_file_to_image(data->mlx_ptr, \
	XPM_FLOO, &data->width, &data->height);
	data->sprites.coll = mlx_xpm_file_to_image(data->mlx_ptr, \
	XPM_COLL_0, &data->width, &data->height);
	data->sprites.exit = mlx_xpm_file_to_image(data->mlx_ptr, \
	XPM_EXIT, &data->width, &data->height);
	data->sprites.play = mlx_xpm_file_to_image(data->mlx_ptr, \
	XPM_PLAY_DOWN_0, &data->width, &data->height);
	return (0);
}

void	init_assets(t_data *data)
{
	data->height = SPR_HEIGHT;
	data->width = SPR_WIDTH;
	/* data->current_frame = 0;
	data->player.player_idle_right_1 = mlx_xpm_file_to_image(game->mlx, \
	"assets/player_idle_right_1.xpm", &game->width, &game->height); */
	if (load_assets(data) == 1)
		write(1, "failed to open the image\n", 25);
}