/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:40:36 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 23:33:44 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "render.h"

/**
 * @brief Renders the move count.
 *
 * @param game Pointer to the game structure.
 * @param buffer Pointer to the image buffer.
 * @param number The number of moves.
 */
static void	render_moves_count(t_game *game, t_img *buffer, int number)
{
	int	i;
	int	unit;

	i = -1;
	while (++i < 4)
	{
		unit = number % 10;
		put_image_to_buffer(buffer, game->textures.number[unit], \
			454 - ((game->textures.number->width + 8) * i), 593);
		number /= 10;
	}
}

/**
 * @brief Renders a mob.
 *
 * @param g Pointer to the game structure.
 * @param buffer Pointer to the image buffer.
 * @param enemy_number The number of enemies.
 */
static void	render_mob(t_game *g, t_img *buffer, int enemy_number)
{
	int		number;
	t_pos	pos;

	number = -1;
	while (++number < enemy_number)
	{
		pos.x = g->mobs[number].pos.x - (g->player.x - 6);
		pos.y = g->mobs[number].pos.y - (g->player.y - 4);
		if ((pos.x >= 0 && pos.x <= 12) && (pos.y >= 0 && pos.y <= 8))
			put_image_to_buffer(buffer, g->textures.mob->img, \
				64 * pos.x + (g->move_pl_px.x + g->mobs[number].move_px), \
				64 * pos.y + g->move_pl_px.y);
	}
}

/**
 * @brief Creates a new image buffer.
 *
 * @param game Pointer to the game structure.
 * @return Returns the created image buffer.
 */
static t_img	create_buffer(t_game *game)
{
	t_img	buffer;

	buffer.ptr = mlx_new_image(game->mlx, 832, 704);
	buffer.addr = mlx_get_data_addr(buffer.ptr, &buffer.bpp, \
		&buffer.line_len, &buffer.endian);
	buffer.width = 832;
	buffer.height = 704;
	return (buffer);
}

/**
 * @brief Renders the game.
 *
 * @param game Pointer to the game structure.
 * @return Always returns 0.
 */
int	render(t_game *game)
{
	t_pos	pl;
	t_img	buffer;

	buffer = create_buffer(game);
	pl.x = game->player.x - 6;
	pl.y = game->player.y - 4;
	render_map(game, &buffer, pl);
	if (game->state == GAME_ON || game->state == GAME_WIN)
		put_image_to_buffer(&buffer, game->textures.current->img, \
			6 * 64, 4 * 64);
	else
		put_image_to_buffer(&buffer, game->textures.dead, \
			6 * 64, 4 * 64);
	render_mob(game, &buffer, game->content.count_mob);
	put_image_to_buffer(&buffer, game->textures.border[game->state], 0, 0);
	render_moves_count(game, &buffer, game->count_moves);
	mlx_put_image_to_window(game->mlx, game->win, buffer.ptr, 0, 0);
	mlx_destroy_image(game->mlx, buffer.ptr);
	return (0);
}
