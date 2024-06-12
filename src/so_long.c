/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:28:53 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/06/12 18:22:14 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
#include "so_long.h"

/* int	main(int argc, char *argv[])
{
	// check args --> send to error check function, maybe in new file
	if (argc != 2)
		ft_putchar_fd("Invalid number of arguments.\n", 2);
	
	
	// check map --> together with check args? or not?
	// initialize window --> in a different file?
	
} */

t_img	new_file_img(char * path, t_win window) {
	t_img image;

	image.win = window;
	image.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, path, &image.w, &image.h);
	if (!image.img_ptr)
		write(2, "File could not be read\n", 23);
	else
		image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	return (image);
}

unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr
			+ (pixel_y * img.line_len) + (pixel_x * img.bpp / 8))));
}

int main(void)
{
 	t_win	tutorial;

	tutorial = new_window(600, 500, "animations");
	if (!tutorial.win_ptr)
		return (2);
	image = new_img(600, 500, tutorial);

	{
		/* Put white pixel */
		put_pixel_img(image, 150, 150, 0x00FFFFFF);
		mlx_put_image_to_window (image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0, 0);
		destroy_image(image);
	}
	{
		/* Put image */
		t_img	tloz_img;
		tloz_img = new_file_img("assets/link.xpm", tutorial);
		if (!tloz_img.img_ptr)
			return (1);
		mlx_put_image_to_window (tloz_img.win.mlx_ptr, tloz_img.win.win_ptr, tloz_img.img_ptr, 0, 0);	
		destroy_image(tloz_img);
	}
	mlx_loop(tutorial.mlx_ptr);
	destroy_window(tutorial);
	return (0);
}
