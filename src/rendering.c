/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:20:57 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/07/26 16:08:28 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	render_background(t_img *img, int color) //Obsolete
{
    int	i;
    int	j;

    i = 0;
    while (i < WIN_HEIGHT)
    {
        j = 0;
        while (j < WIN_WIDTH)
            img_pix_put(img, j++, i, color);
        ++i;
    }
} */

/* int render_rect(t_img *img, t_rect rect) //Obsolete
{
    int	i;
    int j;

    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            img_pix_put(img, j++, i, rect.color);
        ++i;
    }
    return (0);
} */

//void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
//int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
/* int render_spr(char *sprite, t_data *data)
{
	mlx_xpm_file_to_image(data->mlx_ptr, sprite, &data->spr_size, &data->spr_size);
} */

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	//render_background(&data->img, GREY_PIXEL);
	//render_rect(&data->img, (t_rect){WIN_WIDTH - 100, WIN_HEIGHT - 100, 100, 100, YELLOW_PIXEL});
	//render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, XPM_WALL, &data->spr_size, &data->spr_size);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}