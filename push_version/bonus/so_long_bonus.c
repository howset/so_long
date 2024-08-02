/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetya <hsetya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:28:53 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/01 23:11:35 by hsetya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_args(int argc, char *argv);
t_data	initialize_gdata(t_data *gdata);
void	initialize_sprites(t_data *gdata);

int	main(int argc, char *argv[])
{
	t_data	gdata;

	check_args(argc, argv[1]);
	initialize_gdata(&gdata);
	map_load(argv[1], &gdata);
	map_check_elements(&gdata);
	map_check_form(&gdata);
	map_check_ff(&gdata);
	initialize_mlx(&gdata);
	rendering(&gdata);
	run_mlx(&gdata);
	return (0);
}

// preliminary checks (argument checks)
void	check_args(int argc, char *argv)
{
	int		fd;
	int		i;
	int		j;

	if (argc != 2)
		quit_message(NULL, "Error\nInvalid number of arguments.");
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		quit_message(NULL, "Error\nFile does not exist.");
	close(fd);
	i = ft_strlen(argv) - 4;
	j = ft_strncmp(".ber", &argv[i], 4);
	if (j != 0)
		quit_message(NULL, "Error\nOnly accepts .ber files.");
}

// initialize_gdata initializes values in the struct gdata.
t_data	initialize_gdata(t_data *gdata)
{
	gdata->mlx_ptr = NULL;
	gdata->win_ptr = NULL;
	gdata->map_details.map = NULL;
	gdata->map_details.maprows = 0;
	gdata->map_details.mapcols = 0;
	gdata->map_details.coll_check = 0;
	gdata->map_details.exit_check = 0;
	gdata->map_details.play_check = 0;
	gdata->map_details.pl_pos_x = 0;
	gdata->map_details.pl_pos_y = 0;
	gdata->map_details.ex_pos_x = 0;
	gdata->map_details.ex_pos_y = 0;
	gdata->map_details.coll_ff = 0;
	gdata->spr_size = SPR_SIZE;
	gdata->movement = 0;
	gdata->frame = 0;
	initialize_sprites(gdata);
	return (*gdata);
}

//separated because too long
void	initialize_sprites(t_data *gdata)
{
	gdata->sprites.wall = NULL;
	gdata->sprites.floo = NULL;
	gdata->sprites.coll0 = NULL;
	gdata->sprites.coll1 = NULL;
	gdata->sprites.exit = NULL;
	gdata->sprites.play0 = NULL;
	gdata->sprites.play1 = NULL;
	gdata->sprites.play2 = NULL;
	gdata->sprites.play3 = NULL;
	gdata->sprites.snek0 = NULL;
	gdata->sprites.snek1 = NULL;
	gdata->sprites.snek2 = NULL;
	gdata->sprites.snek3 = NULL;
	gdata->sprites.move = NULL;
}
