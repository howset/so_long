/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:41:58 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 23:49:06 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/**
 * @brief Handles the player's movement in the left direction.
 *
 * @param game Pointer to the game structure.
 */
static void	left_direction(t_game *game)
{
	t_pos	pl;

	pl = game->player;
	if (!game->hook.anim.right && !game->hook.anim.down && \
		!game->hook.anim.up && is_valid_path(game, pl.x - 1, pl.y))
	{
		game->hook.anim.left = 1;
		game->hook.is_anim = 1;
		game->move_pl_px.x += 4;
		if (game->move_pl_px.x == 64)
		{
			game->move_pl_px.x = 0;
			move_dir(pl.x - 1, pl.y, game);
			game->hook.anim.left = 0;
			game->hook.is_anim = 0;
		}
	}
}

/**
 * @brief Handles the player's movement in the right direction.
 *
 * @param game Pointer to the game structure.
 */
static void	right_direction(t_game *game)
{
	t_pos	pl;

	pl = game->player;
	if (!game->hook.anim.left && !game->hook.anim.down && \
		!game->hook.anim.up && is_valid_path(game, pl.x + 1, pl.y))
	{
		game->hook.anim.right = 1;
		game->hook.is_anim = 1;
		game->move_pl_px.x -= 4;
		if (game->move_pl_px.x == -64)
		{
			game->move_pl_px.x = 0;
			move_dir(pl.x + 1, pl.y, game);
			game->hook.anim.right = 0;
			game->hook.is_anim = 0;
		}
	}
}

/**
 * @brief Handles the player's movement in the down direction.
 *
 * @param game Pointer to the game structure.
 */
static void	down_direction(t_game *game)
{
	t_pos	pl;

	pl = game->player;
	if (!game->hook.anim.up && !game->hook.anim.left && \
		!game->hook.anim.right && is_valid_path(game, pl.x, pl.y + 1))
	{
		game->hook.anim.down = 1;
		game->hook.is_anim = 1;
		game->move_pl_px.y -= 4;
		if (game->move_pl_px.y == -64)
		{
			game->move_pl_px.y = 0;
			move_dir(pl.x, pl.y + 1, game);
			game->hook.anim.down = 0;
			game->hook.is_anim = 0;
		}
	}
}

/**
 * @brief Handles the player's movement in the up direction.
 *
 * @param game Pointer to the game structure.
 */
static void	up_direction(t_game *game)
{
	t_pos	pl;

	pl = game->player;
	if (!game->hook.anim.down && !game->hook.anim.left && \
		!game->hook.anim.right && is_valid_path(game, pl.x, pl.y - 1))
	{
		game->hook.anim.up = 1;
		game->hook.is_anim = 1;
		game->move_pl_px.y += 4;
		if (game->move_pl_px.y == 64)
		{
			game->move_pl_px.y = 0;
			move_dir(pl.x, pl.y - 1, game);
			game->hook.anim.up = 0;
			game->hook.is_anim = 0;
		}
	}
}

/**
 * @brief Moves the player based on the current game state and direction.
 *
 * @param game Pointer to the game structure.
 */
void	move_player(t_game *game)
{
	if (game->state == GAME_ON && \
		(game->hook.dir.left || game->hook.anim.left))
		left_direction(game);
	if (game->state == GAME_ON && \
		(game->hook.dir.right || game->hook.anim.right))
		right_direction(game);
	if (game->state == GAME_ON && \
		(game->hook.dir.down || game->hook.anim.down))
		down_direction(game);
	if (game->state == GAME_ON && \
		(game->hook.dir.up || game->hook.anim.up))
		up_direction(game);
}
