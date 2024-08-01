/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:20:57 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/07/18 15:37:31 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_background(t_img *bg, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			img_pix_put(bg, j++, i, color);
		++i;
	}
}

t_img	render_bg(int width, int height, t_sl *sl, int color)
{
	t_img	bg;

	bg.img_ptr = mlx_new_image(sl->mlx_ptr, width, height);
	bg.addr = mlx_get_data_addr(bg.img_ptr, &bg.bpp,
			&bg.line_len, &bg.endian);
	
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
			img_pix_put(&bg, j++, i, color);
		++i;
	}
	return (bg);
}

int render_rect(t_img *bg, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(bg, j++, i, rect.color);
		++i;
	}
	return (0);
}

/* int	render_sprite(t_win **data, t_sprite sprite)
{
	(*data)->img.mlx_img = mlx_xpm_file_to_image((*data)->mlx_ptr, sprite.filename, &sprite.width, &sprite.height);
	return (0);
} */

/* int	render_sprite(t_sl *sl, t_xpm xpm)
{
	//mlx_xpm_file_to_image((sl->mlx_ptr, PLAYER_XPM, &xpm.width, &xpm.height);
	sl->layer1.img.ptr = mlx_xpm_file_to_image(sl->mlx_ptr, PLAYER_XPM, &xpm.width, &xpm.height);
	return (0);
} */

int	render(t_sl *sl)
{
//	t_img	bg;
	
	if (sl->win_ptr == NULL)
		return (1);
	render_background(&sl->bg, GREY_PIXEL);
	render_rect(&sl->bg, (t_rect){100, 100,
			100, 100, YELLOW_PIXEL});
	//render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	render_rect(&sl->bg, (t_rect){0, 0, 100, 100, RED_PIXEL});
	//render_sprite(sl, (t_xpm){0, 0, 0, 0});
	//mlx_xpm_file_to_image(&sl->mlx_ptr, PLAYER_XPM, &xpm.width, &xpm.height);
	//render_sprite(data, (t_sprite){XPM_WALL, 0, 0, 0});
	//render_sprite()
	mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->bg.mlx_img, 0, 0);
	//bg = 
	return (0);
}