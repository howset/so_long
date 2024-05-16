/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:18:57 by tanas             #+#    #+#             */
/*   Updated: 2023/02/28 20:03:16 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycodes.h"

int	close_window(t_img *image)
{
	ft_free_double((void **) image->map.z_values);
	ft_free_double((void **) image->map.colours);
	mlx_destroy_window(image->win.mlx, image->win.window);
	mlx_destroy_image(image->win.mlx, image->img);
	#ifdef __LINUX__
		mlx_destroy_display(image->win.mlx); // only works in linux!
	#endif
	free(image->win.mlx);
	exit(0);
}

static void	move_hook(int key, t_img image)
{
	if (key == ARROW_UP)
		image.camera->y_offset -= 10;
	else if (key == ARROW_DOWN)
		image.camera->y_offset += 10;
	else if (key == ARROW_LEFT)
		image.camera->x_offset -= 10;
	else if (key == ARROW_RIGHT)
		image.camera->x_offset += 10;
	draw(image);
}

static void	rotate_hook(int key, t_img image)
{
	if (key == KEY_A)
		image.camera->alpha += (M_PI / 180);
	else if (key == KEY_D)
		image.camera->alpha -= (M_PI / 180);
	else if (key == KEY_E)
		image.camera->beta += (M_PI / 180);
	else if (key == KEY_Q)
		image.camera->beta -= (M_PI / 180);
	else if (key == KEY_W)
		image.camera->gamma += (M_PI / 180);
	else if (key == KEY_S)
		image.camera->gamma -= (M_PI / 180);
	else if (key == KEY_T)
	{
		image.camera->view = TOP;
		image.camera->alpha = 0;
		image.camera->beta = 0;
		image.camera->gamma = 0;
	}
	else if (key == KEY_I)
		image.camera->view = ISOMETRIC;
	draw(image);
}

static void	zoom_hook(int key, t_img image)
{
	if (key == NUMPAD_PLUS || key == PLUS)
		image.camera->zoom += 1;
	else if (key == NUMPAD_MINUS || key == MINUS)
		image.camera->zoom -= 1;
	else if (key == MORE)
		image.camera->z_value += 0.1;
	else if (key == LESS)
		image.camera->z_value -= 0.1;
	if (image.camera->z_value < 0.1)
		image.camera->z_value = 0.1;
	if (image.camera->z_value > 10)
		image.camera->z_value = 10;
	draw(image);
}

int	key_events(int key, t_img *image)
{
	ft_memset(image->addr, 0, (HEIGHT * WIDTH * 4));
	if (key == ESCAPE)
		close_window(image);
	else if (key == KEY_A || key == KEY_W || key == KEY_S || \
		key == KEY_Q || key == KEY_E || key == KEY_D || \
		key == KEY_T || key == KEY_I)
		rotate_hook(key, *image);
	else if (key == NUMPAD_MINUS || key == NUMPAD_PLUS || key == PLUS || \
		key == MINUS || key == MORE || key == LESS)
		zoom_hook(key, *image);
	else if (key == ARROW_DOWN || key == ARROW_LEFT || \
		key == ARROW_UP || key == ARROW_RIGHT)
		move_hook(key, *image);
	else if (key == KEY_R)
		reset(*image);
	return (0);
}
