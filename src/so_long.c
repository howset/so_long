/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:28:53 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/07/31 15:04:43 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	gdata;
	
	check_args(argc, argv[1]);
	initialize_gdata(&gdata);
	map_load(argv[1], &gdata);
	check_elements(&gdata);
	initialize_mlx(&gdata);
	rendering(&gdata);
	run_mlx(&gdata);
	return (0);
}