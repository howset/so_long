/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:35:38 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/07/31 14:11:35 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	run_mlx(t_data *gdata)
{
	mlx_hook(gdata->win_ptr, KeyPress, KeyPressMask, key_press, gdata); 
	mlx_hook(gdata->win_ptr, KeyRelease, KeyReleaseMask, key_release, gdata);
	mlx_hook(gdata->win_ptr, DestroyNotify, StructureNotifyMask, on_quit, gdata);
	mlx_loop(gdata->mlx_ptr);
}