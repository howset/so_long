/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:30:39 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 23:42:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "hooks.h"
#include "textures.h"

/**
 * @brief Closes the game and frees allocated resources.
 *
 * @param game Pointer to the game structure.
 * @return Always returns 0.
 */
int	game_close(t_game *game)
{
	if (game->map)
		ft_freetab(game->map);
	free(game->mobs);
	clear_textures(game);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
}

/**
 * @brief Handles the event when a direction key is pressed.
 *
 * @param sprites Pointer to the sprites structure.
 * @param game Pointer to the game structure.
 * @param dir Pointer to the direction.
 * @param is_last Boolean indicating if this is the last key pressed.
 */
static void	dir_pressed(t_sprite *sprites, t_game *game, int *dir, bool is_last)
{
	if (*dir == 0)
	{
		*dir = 1;
		if (!is_last)
		{
			game->textures.current = sprites;
			game->textures.current_back = sprites;
		}
	}
}

/**
 * @brief Handles the event when a key is pressed.
 *
 * @param key The key code of the pressed key.
 * @param game Pointer to the game structure.
 * @return Always returns 0.
 */
int	key_pressed(int key, t_game *game)
{
	static int	last_key = 0;

	if (key == KEY_ESC)
		game_close(game);
	else if (key == KEY_L && game->state == GAME_ON)
		dir_pressed(game->textures.left, game, &game->hook.dir.left, \
			last_key == key);
	else if (key == KEY_R && game->state == GAME_ON)
		dir_pressed(game->textures.right, game, &game->hook.dir.right, \
			last_key == key);
	else if (key == KEY_D && game->state == GAME_ON)
		dir_pressed(game->textures.down, game, &game->hook.dir.down, \
			last_key == key);
	else if (key == KEY_U && game->state == GAME_ON)
		dir_pressed(game->textures.up, game, &game->hook.dir.up, \
			last_key == key);
	last_key = key;
	return (0);
}

/**
 * @brief Handles the event when a key is released.
 *
 * @param key The key code of the released key.
 * @param game Pointer to the game structure.
 * @return Always returns 0.
 */
int	key_released(int key, t_game *game)
{
	if (key == KEY_L && game->state == GAME_ON)
		game->hook.dir.left = 0;
	else if (key == KEY_R && game->state == GAME_ON)
		game->hook.dir.right = 0;
	else if (key == KEY_D && game->state == GAME_ON)
		game->hook.dir.down = 0;
	else if (key == KEY_U && game->state == GAME_ON)
		game->hook.dir.up = 0;
	return (0);
}
