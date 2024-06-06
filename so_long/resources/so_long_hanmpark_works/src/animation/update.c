/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:42:24 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 23:44:51 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "render.h"

/**
 * @brief Gets the current time in milliseconds.
 *
 * @return Returns the current time in milliseconds.
 */
long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/**
 * @brief Manages the frames per second (FPS) of the game.
 *
 * @param game Pointer to the game structure.
 */
static void	fps(t_game *game)
{
	long long	elapsed_time;
	long long	sleep_time;

	game->current_time = get_time();
	elapsed_time = game->current_time - game->last_time;
	sleep_time = (1000 / FPS) - elapsed_time;
	game->last_time = game->current_time;
	if (sleep_time > 0)
		usleep(sleep_time * 1000);
}

/**
 * @brief Updates the game state.
 *
 * @param game Pointer to the game structure.
 * @return Always returns 0.
 */
int	update(t_game *game)
{
	fps(game);
	game->frames++;
	if (game->frames < 0)
		game->frames = 0;
	check_game(game, game->player, game->mobs);
	anim_collectible(game);
	anim_enemy(game);
	if (game->state == GAME_ON)
		anim_player(game);
	if (game->move_enemy)
		move_enemy(game);
	move_player(game);
	render(game);
	return (0);
}
