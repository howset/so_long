/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:16:34 by tanas             #+#    #+#             */
/*   Updated: 2023/02/26 21:15:21 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu_bg(t_img image)
{
	int	y;
	int	x;

	y = 20;
	while (y < MENU_HEIGHT)
	{
		x = 20;
		while (x < MENU_WIDTH)
		{
			my_pixel_put(image, x, y, 0x280064);
			x++;
		}
		y++;
	}
}

void	print_menu(t_win win)
{
	mlx_string_put(win.mlx, win.window, 30, 25, WHITE, "Controls:");
	mlx_string_put(win.mlx, win.window, 30, 45, WHITE, "===============");
	mlx_string_put(win.mlx, win.window, 30, 70, WHITE, "Zoom: +/-");
	mlx_string_put(win.mlx, win.window, 30, 90, WHITE, "Move: UP/DOWN key");
	mlx_string_put(win.mlx, win.window, 30, 110, WHITE, "Isometric View: I");
	mlx_string_put(win.mlx, win.window, 30, 130, WHITE, "Top View: T");
	mlx_string_put(win.mlx, win.window, 30, 150, WHITE, "Rotate X: E/Q");
	mlx_string_put(win.mlx, win.window, 30, 170, WHITE, "Rotate Y: A/D");
	mlx_string_put(win.mlx, win.window, 30, 190, WHITE, "Rotate Z: W/S");
	mlx_string_put(win.mlx, win.window, 30, 210, WHITE, "Change Z: </>");
	mlx_string_put(win.mlx, win.window, 30, 230, WHITE, "Reset Changes: R");
	mlx_string_put(win.mlx, win.window, 30, 260, WHITE, "===============");
}
