/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:10:12 by tanas             #+#    #+#             */
/*   Updated: 2023/02/28 16:47:57 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset(t_img image)
{
	if (image.map.width <= 50 || image.map.height <= 50)
		image.camera->zoom = 10;
	else
		image.camera->zoom = 1;
	image.camera->alpha = 0;
	image.camera->beta = 0;
	image.camera->gamma = 0;
	image.camera->z_value = 1;
	image.camera->x_offset = 0;
	image.camera->y_offset = 0;
	image.camera->view = ISOMETRIC;
	draw(image);
}

static void	initialize_camera(t_camera *camera, t_map map)
{
	if (map.width <= 50 || map.height <= 50)
		camera->zoom = 10;
	else
		camera->zoom = 1;
	camera->z_value = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->view = ISOMETRIC;
}

int	main(int argc, char **argv)
{
	t_win		fdf;
	t_img		image;
	t_camera	camera;

	if (check_file(argv[1], argc))
	{
		ft_bzero(&fdf, sizeof(t_win));
		ft_bzero(&image, sizeof(t_img));
		ft_bzero(&camera, sizeof(t_camera));
		fdf = make_window(WIDTH, HEIGHT, argv[1]);
		if (!fdf.mlx || !fdf.window)
			return (1);
		image = make_image(WIDTH, HEIGHT, fdf);
		image.map = get_map(argv[1]);
		initialize_camera(&camera, image.map);
		image.camera = &camera;
		draw(image);
		mlx_hook(fdf.window, 2, 1L << 0, key_events, &image);
		mlx_hook(fdf.window, 17, 1L << 17, close_window, &image);
		mlx_loop(fdf.mlx);
	}
}
