/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 02:51:09 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 23:43:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "hooks.h"
#include "render.h"
#include "textures.h"

/**
 * @brief Creates a new window and renders the game.
 *
 * @param game Pointer to the game structure.
 * @param x Width of the window.
 * @param y Height of the window.
 */
static void	new_window(t_game *game, int x, int y)
{
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
	render(game);
}

/**
 * @brief Initializes the game data.
 *
 * @param game Pointer to the game structure.
 */
static void	data_init(t_game *game)
{
	game->move_pl_px.x = 0;
	game->move_pl_px.y = 0;
	game->hook.dir.left = 0;
	game->hook.dir.right = 0;
	game->hook.dir.up = 0;
	game->hook.dir.down = 0;
	game->hook.anim.left = 0;
	game->hook.anim.right = 0;
	game->hook.anim.up = 0;
	game->hook.anim.down = 0;
	game->hook.is_anim = 0;
	game->frames = 0;
	game->exit = 0;
	game->count_moves = 0;
	game->move_enemy = STILL_ENEMY;
	game->state = GAME_ON;
	game->textures.current_exit = game->textures.exit[0];
	game->last_time = get_time();
}

/**
 * @brief Initializes the game.
 *
 * @param game Pointer to the game structure.
 * @return Returns true on success, false on error.
 */
bool	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (send_error(game->map, game->mobs, ERR_MLX));
	assign_textures(game);
	data_init(game);
	new_window(game, 832, 704);
	mlx_hook(game->win, 17, 0, &game_close, game);
	mlx_hook(game->win, KEYPRESS, KEYPRESS_MASK, &key_pressed, game);
	mlx_hook(game->win, KEYRELEASE, KEYRELEASE_MASK, &key_released, game);
	mlx_loop_hook(game->mlx, &update, game);
	mlx_loop(game->mlx);
	return (true);
}
