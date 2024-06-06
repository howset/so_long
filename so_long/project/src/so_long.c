/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:28:53 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/06/06 17:47:48 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
#include "so_long.h"
#include <stdio.h>

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	handle_no_event(void)
{
    return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);

    printf("Keypress: %d\n", keysym);
    return (0);
}

int	handle_keyrelease(int keysym)
{
    printf("Keyrelease: %d\n", keysym);
    return (0);
}

int	main(void)
{
    t_data	data;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 640, 360, "Testing AB blog!");
    if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        return (1);
    }
    mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
    //mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); 
    mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
    mlx_loop(data.mlx_ptr);
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
}