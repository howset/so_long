/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:28:53 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/05/20 14:30:42 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
#include "so_long.h"
#include <string.h>

t_win new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

int main(void)
{
	/**
	 *	void	*mlx_ptr;
	 *	void	*win_ptr;
	 *
	 *	mlx_ptr = mlx_init();
	 *	if (!mlx_ptr)
	 *		return (1);
	 *	win_ptr = mlx_new_window (mlx_ptr, 300, 300, "Hello World");
	 *	if (!win_ptr)
	 *		return (2);
	 *	mlx_loop(mlx_ptr);
	 **/
	t_win tutorial;
	
	tutorial = new_program(600, 600, "New Program");
	if (!tutorial.mlx_ptr || !tutorial.win_ptr)
		return (1);
	{
		t_img	image_4x4;

		image_4x4.win = tutorial;
		image_4x4.img_ptr = mlx_new_image(tutorial.mlx_ptr, 4, 4);
		image_4x4.addr = mlx_get_data_addr(image_4x4.img_ptr, &(image_4x4.bpp), &(image_4x4.line_len), &(image_4x4.endian));
		image_4x4.width = 4;
		image_4x4.height = 4;
		memcpy(image_4x4.addr, "s4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vf", 16*4);
		mlx_put_image_to_window (image_4x4.win.mlx_ptr, image_4x4.win.win_ptr, image_4x4.img_ptr, 10, 10);
		/* printf("Let's Find out what's inside our structure :D\n");
		printf("img_ptr		: [%p]\n", image_4x4.img_ptr);
		printf("bpp		: [%d]\n", image_4x4.bpp);
		printf("line_len	: [%d]\n", image_4x4.line_len);
		printf("endian		: [%d]\n", image_4x4.endian);
		printf("addr		: [%p]\n", image_4x4.addr); */
	} 
	mlx_loop(tutorial.mlx_ptr); 
	return (0);
}
