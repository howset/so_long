/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:28:53 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/06/17 10:28:47 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_win	window;

	window.mlx_ptr = mlx_init();
	if (window.mlx_ptr == NULL)
		return (1);
	window.win_ptr = mlx_new_window(window.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Putting xpms");
	if (window.win_ptr == NULL)
	{
		free(window.win_ptr);
		return (1);
	}
	window.bg.mlx_img = mlx_new_image(window.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	window.bg.addr = mlx_get_data_addr(window.bg.mlx_img, &window.bg.bpp,
			&window.bg.line_len, &window.bg.endian);
	mlx_loop_hook(window.mlx_ptr, &render, &window);
	mlx_hook(window.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &window); 
	mlx_hook(window.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &window);
	mlx_hook(window.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &window);
	mlx_loop(window.mlx_ptr);
	mlx_destroy_image(window.mlx_ptr, window.bg.mlx_img);
	mlx_destroy_display(window.mlx_ptr);
	free(window.mlx_ptr);
}
