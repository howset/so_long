/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:38:46 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/07/31 15:05:45 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keysym, t_data *gdata)
{
	if (keysym == XK_Escape)
		on_quit(gdata);
	else if (keysym == XK_W || keysym == XK_Up)
		update_player_pos(gdata, 0, -1);
		//ft_printf("Movement: %d\n", gdata->movement += 1);
	else if (keysym == XK_S || keysym == XK_Down)
		update_player_pos(gdata, 0, 1);
		//ft_printf("Movement: %d\n", gdata->movement += 1);
	else if (keysym == XK_A || keysym == XK_Left)
		update_player_pos(gdata, 1, -1);
		//ft_printf("Movement: %d\n", gdata->movement += 1);
	else if (keysym == XK_D || keysym == XK_Right)
		update_player_pos(gdata, 1, 1);
		//ft_printf("Movement: %d\n", gdata->movement += 1);
	return (0);
}
