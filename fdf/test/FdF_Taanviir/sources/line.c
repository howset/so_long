/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:02:57 by tanas             #+#    #+#             */
/*   Updated: 2023/02/26 16:02:18 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static int	ft_swap(t_data *data)
{
	int	tmp;

	if (data->dx < data->dy)
	{
		tmp = data->dx;
		data->dx = data->dy;
		data->dy = tmp;
		return (1);
	}
	return (0);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static void	fill(t_data *data, t_coord c1, t_coord c2)
{
	data->dx = ft_abs(c2.x - c1.x);
	data->dy = ft_abs(c2.y - c1.y);
	data->s1 = get_sign(c2.x - c1.x);
	data->s2 = get_sign(c2.y - c1.y);
}

void	draw_line(t_coord c1, t_coord c2, t_img image)
{
	int		i;
	int		swap;
	t_data	data;

	project(&c1, image);
	project(&c2, image);
	fill(&data, c1, c2);
	swap = ft_swap(&data);
	data.decision = 2 * data.dy - data.dx;
	i = 0;
	while (i <= data.dx)
	{
		my_pixel_put(image, c1.x, c1.y, c1.colour);
		while (data.decision > 0)
		{
			data.decision -= (2 * data.dx);
			c1.x += (data.s1 * swap);
			c1.y += (data.s2 * !swap);
		}
		data.decision += (2 * data.dy);
		c1.y += (data.s2 * swap);
		c1.x += (data.s1 * !swap);
		i++;
	}
}
