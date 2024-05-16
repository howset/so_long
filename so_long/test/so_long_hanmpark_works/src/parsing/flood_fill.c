/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 02:20:39 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 23:42:02 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"

/**
 * @brief Performs the flood fill algorithm on the game map.
 *
 * @param x X-coordinate of the starting point.
 * @param y Y-coordinate of the starting point.
 * @param draftmap The game map.
 * @param g Pointer to the game structure.
 * @return Returns true if the flood fill was successful, false otherwise.
 */
static bool	filling(int x, int y, char **draftmap, t_game *g)
{
	static int	collectible = 0;
	static int	exit = 0;

	if (x < 0 || y < 0 || x >= g->size.x || y >= g->size.y)
		return (false);
	if (draftmap[y][x] == 'F' || draftmap[y][x] == '1' || \
		draftmap[y][x] == 'M')
		return (false);
	else if (draftmap[y][x] == 'C')
		collectible++;
	else if (draftmap[y][x] == 'E')
		exit++;
	draftmap[y][x] = 'F';
	filling(x - 1, y, draftmap, g);
	filling(x + 1, y, draftmap, g);
	filling(x, y - 1, draftmap, g);
	filling(x, y + 1, draftmap, g);
	if (collectible != g->content.collectible || !exit)
		return (false);
	return (true);
}

/**
 * @brief Performs the flood fill algorithm on the game map.
 *
 * @param game Pointer to the game structure.
 * @param tmpmap The game map.
 * @return Returns true if the flood fill was successful, false otherwise.
 */
bool	flood_fill(t_game *game, char **tmpmap)
{
	if (!filling(game->player.x, game->player.y, tmpmap, game))
	{
		ft_freetab(tmpmap);
		return (false);
	}
	ft_freetab(tmpmap);
	return (true);
}
