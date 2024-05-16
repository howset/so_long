/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:10:17 by tanas             #+#    #+#             */
/*   Updated: 2023/02/24 20:48:32 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win	make_window(int w, int h, char *title)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, w, h, title), w, h});
}

void	my_pixel_put(t_img image, int x, int y, int color)
{
	if (y >= 0 && x >= 0 && x < WIDTH && y < HEIGHT)
		*(unsigned int *)(image.addr + \
			(y * image.line_length + x * (image.bpp / 8))) = color;
}

t_img	make_image(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img = mlx_new_image(window.mlx, w, h);
	image.addr = mlx_get_data_addr(image.img, &image.bpp,
			&image.line_length, &image.endian);
	image.height = h;
	image.width = w;
	return (image);
}
