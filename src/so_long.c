/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:28:53 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/06/14 15:31:19 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
}

void	render_background(t_img *img, int color)
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
}

int render_rect(t_img *img, t_rect rect)
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
}

/* int	render_sprite(t_data **data, t_sprite sprite)
{
	(*data)->img.mlx_img = mlx_xpm_file_to_image((*data)->mlx_ptr, sprite.filename, &sprite.width, &sprite.height);
	return (0);
} */

int	render_sprite(t_img *img, void *mlx_ptr, t_sprite sprite)
{
	img = mlx_xpm_file_to_image(mlx_ptr, sprite.filename, &sprite.width, &sprite.height);
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
        return (1);
	//render_background(&data->img, GREY_PIXEL);
    //render_rect(&data->img, (t_rect){100, 100,
            //100, 100, YELLOW_PIXEL});
    //render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	render_sprite(&data->img, &data->mlx_ptr, (t_sprite){XPM_FLOO, 0, 0, 0});
	//render_sprite(data, (t_sprite){XPM_WALL, 0, 0, 0});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
    return (0);
}

int	handle_keypress(int keysym)
{
	ft_printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	ft_printf("Keyrelease: %d\n", keysym);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Testing keypresses and releases");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (1);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);	
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); 
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
