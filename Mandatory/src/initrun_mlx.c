/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initrun_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:18:33 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/01 16:49:05 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_mlx(t_data *gdata);
void	run_mlx(t_data *gdata);
int		key_press(int keysym, t_data *gdata);

//initialize_mlx starts the mlx and creates a window.
void	initialize_mlx(t_data *gdata)
{
	gdata->mlx_ptr = mlx_init();
	if (gdata->mlx_ptr == NULL)
		quit_message(gdata, "Error\nMlx initialization failed.");
	gdata->win_ptr = mlx_new_window(gdata->mlx_ptr,
			gdata->map_details.mapcols * SPR_SIZE, \
			gdata->map_details.maprows * SPR_SIZE,
			"so_long");
	if (gdata->win_ptr == NULL)
		quit_message(gdata, "Error\nMlx new window failed.");
}

//start mlx loop and hooks key presses.
void	run_mlx(t_data *gdata)
{
	mlx_hook(gdata->win_ptr, KeyPress, KeyPressMask, key_press, gdata);
	mlx_hook(gdata->win_ptr, DestroyNotify, StructureNotifyMask, \
	on_quit, gdata);
	mlx_loop(gdata->mlx_ptr);
}

//handles keypresses.
int	key_press(int keysym, t_data *gdata)
{
	if (keysym == XK_Escape)
		on_quit(gdata);
	else if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
		update_pos(gdata, 0, -1);
	else if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
		update_pos(gdata, 0, 1);
	else if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
		update_pos(gdata, 1, -1);
	else if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
		update_pos(gdata, 1, 1);
	return (0);
}
