/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:07:35 by tanas             #+#    #+#             */
/*   Updated: 2023/02/26 21:15:00 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	new_coord(int x, int y, t_map map)
{
	t_coord	new_coord;

	new_coord.x = x;
	new_coord.y = y;
	new_coord.z = map.z_values[y][x];
	new_coord.colour = map.colours[y][x];
	return (new_coord);
}

void	draw(t_img image)
{
	int	y;
	int	x;

	y = 0;
	while (y < image.map.height)
	{
		x = 0;
		while (x < image.map.width)
		{
			if (x < (image.map.width - 1))
				draw_line(new_coord(x, y, image.map), \
					new_coord(x + 1, y, image.map), image);
			if (y < (image.map.height - 1))
				draw_line(new_coord(x, y, image.map), \
					new_coord(x, y + 1, image.map), image);
			x++;
		}
		y++;
	}
	draw_menu_bg(image);
	mlx_put_image_to_window(image.win.mlx, image.win.window, image.img, 0, 0);
	print_menu(image.win);
}
