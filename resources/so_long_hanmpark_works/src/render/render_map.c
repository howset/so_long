/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:23:07 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 23:34:54 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "render.h"

/**
 * @brief Renders game elements.
 *
 * @param win Window position.
 * @param buffer Pointer to the image buffer.
 * @param pl Player position.
 * @param g Pointer to the game structure.
 */
static void	render_elements(t_pos win, t_img *buffer, t_pos pl, t_game *g)
{
	if ((pl.x % 2 && !(pl.y % 2)) || (!(pl.x % 2) && pl.y % 2))
		put_image_to_buffer(buffer, g->textures.floor[0], \
			64 * win.x + g->move_pl_px.x, 64 * win.y + g->move_pl_px.y);
	else
		put_image_to_buffer(buffer, g->textures.floor[1], \
			64 * win.x + g->move_pl_px.x, 64 * win.y + g->move_pl_px.y);
	if (g->map[pl.y][pl.x] == 'C' || g->map[pl.y][pl.x] == 'T')
		put_image_to_buffer(buffer, g->textures.collectible->img, \
			64 * win.x + g->move_pl_px.x, 64 * win.y + g->move_pl_px.y);
	else if (pl.x == g->content.exit_pos.x && \
		pl.y == g->content.exit_pos.y)
		put_image_to_buffer(buffer, g->textures.current_exit, \
			64 * win.x + g->move_pl_px.x, 64 * win.y + g->move_pl_px.y);
	else if (g->map[pl.y][pl.x] == '1')
		put_image_to_buffer(buffer, g->textures.wall, \
			64 * win.x + g->move_pl_px.x, 64 * win.y + g->move_pl_px.y);
}

/**
 * @brief Renders map elements.
 *
 * @param g Pointer to the game structure.
 * @param buffer Pointer to the image buffer.
 * @param pl Player position.
 * @param win Window position.
 */
static void	render_map_elements(t_game *g, t_img *buffer, t_pos pl, t_pos win)
{
	if (pl.x < 0 || pl.x >= g->size.x || pl.y < 0 || pl.y >= g->size.y)
	{
		put_image_to_buffer(buffer, g->textures.floor[2], \
			64 * win.x + g->move_pl_px.x, 64 * win.y + g->move_pl_px.y);
		put_image_to_buffer(buffer, g->textures.wall, \
			64 * win.x + g->move_pl_px.x, 64 * win.y + g->move_pl_px.y);
	}
	if ((pl.x >= 0 && pl.x < g->size.x) && (pl.y >= 0 && pl.y < g->size.y))
		render_elements(win, buffer, pl, g);
}

/**
 * @brief Renders the game map.
 *
 * @param game Pointer to the game structure.
 * @param buffer Pointer to the image buffer.
 * @param pl Player position.
 */
void	render_map(t_game *game, t_img *buffer, t_pos pl)
{
	int		og;
	t_pos	win;

	og = pl.x;
	win.y = -1;
	while (++win.y < 9)
	{
		win.x = -1;
		pl.x = og;
		while (++win.x < 13)
		{
			render_map_elements(game, buffer, pl, win);
			pl.x++;
		}
		pl.y++;
	}
}
