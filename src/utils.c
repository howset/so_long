/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:22:37 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/07/31 14:38:32 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// remove map array (and free, and set to null)
void	remove_map(t_data *gdata)
{
	int	i;

	i = 0;
	if (gdata->map_details.map == NULL)
		return ;
	while (gdata->map_details.map[i])
	{
		free(gdata->map_details.map[i]);
		gdata->map_details.map[i] = NULL;
		i++;
	}
	free(gdata->map_details.map);
	gdata->map_details.map = NULL;
}

// remove xpm images (destroy)
void	remove_xpm(t_data *gdata)
{
	if (gdata->sprites.wall)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.wall);
	if (gdata->sprites.floo)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.floo);
	if (gdata->sprites.coll)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.coll);
	if (gdata->sprites.exit)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.exit);
	if (gdata->sprites.play)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.play);
	if (gdata->sprites.snek)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.snek);
}

// basic func to remove map, xpm, and destroy window & display
void on_destroy(t_data *gdata)
{
	if (!gdata)
		return ;
	remove_xpm(gdata);
	remove_map(gdata);
	mlx_destroy_window(gdata->mlx_ptr, gdata->win_ptr);
	mlx_destroy_display(gdata->mlx_ptr);
	free(gdata->mlx_ptr);
}

// just on_destroy, but returns int
int	on_quit(t_data *gdata)
{
	on_destroy(gdata);
	exit(0);
	return (0);
}

// calls on_destroy, and write error message
void	quit_message(t_data *gdata, char *error_msg)
{
	on_destroy(gdata);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(1);
}
