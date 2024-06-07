/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:28:53 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/06/07 14:21:33 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
#include "so_long.h"
#include <string.h>

/* typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "One red dot");
	img.img = mlx_new_image(mlx, 200, 200);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
} */

/* t_win new_program(int w, int h, char *str)
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
	 /*
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
		// printf("Let's Find out what's inside our structure :D\n");
		// printf("img_ptr		: [%p]\n", image_4x4.img_ptr);
		// printf("bpp		: [%d]\n", image_4x4.bpp);
		// printf("line_len	: [%d]\n", image_4x4.line_len);
		// printf("endian		: [%d]\n", image_4x4.endian);
		// printf("addr		: [%p]\n", image_4x4.addr);
	} 
	mlx_loop(tutorial.mlx_ptr); 
	return (0);
}
 */

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

/* int	handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);

    printf("Keypress: %d\n", keysym);
    return (0);
} */

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
