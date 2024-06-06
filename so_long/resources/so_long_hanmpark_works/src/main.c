/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:32:12 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 23:29:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"

/**
 * @brief Handles errors by freeing memory and printing an error message.
 *
 * @param map Pointer to the map to be freed.
 * @param data Pointer to the data to be freed.
 * @param str Error message to be printed.
 * @return Always returns false.
 */
bool	send_error(char **map, void *data, char *str)
{
	if (data)
		free(data);
	if (map)
		ft_freetab(map);
	ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\033[0m", 2);
	return (false);
}

/**
 * @brief The entry point of the program.
 *
 * @param argc Number of command line arguments.
 * @param argv Command line arguments.
 * @return Returns 0 on success, non-zero on error.
 */
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		send_error(NULL, NULL, ERR_BER);
		return (1);
	}
	if (!map_init(argv[1], &game))
		return (2);
	else if (!game_init(&game))
		return (3);
	return (0);
}
