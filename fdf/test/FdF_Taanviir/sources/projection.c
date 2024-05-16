/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:49:01 by tanas             #+#    #+#             */
/*   Updated: 2023/02/28 19:39:44 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_coord(t_coord *c, double alpha, double beta, double gamma)
{
	int	x;

	x = c->x;
	c->x = (x * cos(beta) * cos(gamma)) + \
		(c->y * sin(alpha) * sin(beta) * cos(gamma)) - \
		(c->y * cos(alpha) * sin(gamma)) + \
		(c->z * cos(alpha) * sin(beta) * cos(gamma)) + \
		(c->z * sin(alpha) * sin(gamma));
	c->y = (x * cos(beta) * sin(gamma)) + \
		(c->y * sin(alpha) * sin(beta) * sin(gamma)) + \
		(c->y * cos(alpha) * cos(gamma)) + \
		(c->z * cos(alpha) * sin(beta) * sin(gamma)) - \
		(c->z * sin(alpha) * cos(gamma));
}

static void	isometric(int *x, int *y, int z)
{
	int	old_x;
	int	old_y;

	old_x = *x;
	old_y = *y;
	*x = (old_x - old_y) * cos(30 * (M_PI / 180));
	*y = -z + (old_x + old_y) * sin(30 * (M_PI / 180));
}

static void	zoom_and_center(t_coord *c, t_img image)
{
	c->x *= image.camera->zoom;
	c->y *= image.camera->zoom;
	c->z *= image.camera->zoom / image.camera->z_value;
	c->x -= (image.map.width * image.camera->zoom / 2);
	c->y -= (image.map.height * image.camera->zoom / 2);
}

void	project(t_coord *c, t_img image)
{
	zoom_and_center(c, image);
	rotate_coord(c, \
		image.camera->alpha, image.camera->beta, image.camera->gamma);
	if (image.camera->view == ISOMETRIC)
		isometric(&c->x, &c->y, c->z);
	c->x += ((WIDTH + image.camera->x_offset) / 2);
	c->y += ((HEIGHT + image.camera->y_offset) / 2);
}
