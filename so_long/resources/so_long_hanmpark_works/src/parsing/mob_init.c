/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 02:39:24 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 23:40:36 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"

/**
 * @brief Sets enemy data.
 *
 * @param x X-coordinate of the enemy.
 * @param y Y-coordinate of the enemy.
 * @param game Pointer to the game structure.
 * @return Returns the set enemy data.
 */
static t_mob	enemy_data_set(int x, int y, t_game *game)
{
	t_mob	mobs;

	mobs.pos.x = x;
	mobs.pos.y = y;
	mobs.move_px = 0;
	if (is_valid_path(game, x - 1, y))
		mobs.dir = LEFT;
	else if (is_valid_path(game, x + 1, y))
		mobs.dir = RIGHT;
	else
		mobs.dir = STATIC;
	return (mobs);
}

/**
 * @brief Initializes the mobs.
 *
 * @param game Pointer to the game structure.
 * @return Returns true on success, false on error.
 */
bool	mob_init(t_game *game)
{
	int	index;
	int	y;
	int	x;

	game->mobs = ft_calloc(game->content.count_mob, sizeof(t_mob));
	if (!game->mobs)
		return (send_error(game->map, game->mobs, ERR_MALLOC));
	index = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			if (game->map[y][x] == 'M')
				game->mobs[index++] = enemy_data_set(x, y, game);
	}
	return (true);
}
