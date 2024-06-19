/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:28:53 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/06/18 18:49:34 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_sl	sl;

	sl.mlx_ptr = mlx_init();
	if (sl.mlx_ptr == NULL)
		return (1);
	sl.win_ptr = mlx_new_window(sl.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Putting xpms");
	if (sl.win_ptr == NULL)
	{
		free(sl.win_ptr);
		return (1);
	}
	/* sl.bg.mlx_img = mlx_new_image(sl.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	sl.bg.addr = mlx_get_data_addr(sl.bg.mlx_img, &sl.bg.bpp,
			&sl.bg.line_len, &sl.bg.endian); */
	mlx_loop_hook(sl.mlx_ptr, &render, &sl);
	mlx_hook(sl.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &sl); 
	mlx_hook(sl.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &sl);
	mlx_hook(sl.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &sl);
	mlx_loop(sl.mlx_ptr);
	//mlx_destroy_image(sl.mlx_ptr, sl.mlx_img);
	mlx_destroy_display(sl.mlx_ptr);
	free(sl.mlx_ptr);
}
