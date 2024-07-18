/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:21:56 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/07/18 16:48:27 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym)
{
	ft_printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	ft_printf("Keyrelease: %d\n", keysym);
	if (keysym == XK_Escape)
	{
		/* mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL; */
		on_destroy(data);
	}
	return (0);
}
