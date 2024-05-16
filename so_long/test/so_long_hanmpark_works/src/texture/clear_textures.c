/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 02:55:23 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 23:32:20 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/**
 * @brief Clears a sprite.
 *
 * @param sprite Pointer to the pointer to the sprite to be cleared.
 * @param g Pointer to the game structure.
 */
static void	clear_sprite(t_sprite **sprite, t_game *g)
{
	t_sprite	*current_sprite;
	t_sprite	*next_sprite;

	current_sprite = *sprite;
	while (current_sprite)
	{
		next_sprite = current_sprite->next;
		mlx_destroy_image(g->mlx, current_sprite->img.ptr);
		free(current_sprite);
		current_sprite = next_sprite;
	}
	*sprite = NULL;
}

/**
 * @brief Clears environment textures.
 *
 * @param g Pointer to the game structure.
 */
static void	clear_environment_textures(t_game *g)
{
	mlx_destroy_image(g->mlx, g->textures.wall.ptr);
	mlx_destroy_image(g->mlx, g->textures.floor[0].ptr);
	mlx_destroy_image(g->mlx, g->textures.floor[1].ptr);
	mlx_destroy_image(g->mlx, g->textures.floor[2].ptr);
	mlx_destroy_image(g->mlx, g->textures.exit[0].ptr);
	mlx_destroy_image(g->mlx, g->textures.exit[1].ptr);
	mlx_destroy_image(g->mlx, g->textures.border[0].ptr);
	mlx_destroy_image(g->mlx, g->textures.border[1].ptr);
	mlx_destroy_image(g->mlx, g->textures.border[2].ptr);
}

/**
 * @brief Clears number textures.
 *
 * @param g Pointer to the game structure.
 */
static void	clear_numbers_textures(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 10)
		mlx_destroy_image(g->mlx, g->textures.number[i].ptr);
}

/**
 * @brief Clears all textures.
 *
 * @param g Pointer to the game structure.
 */
void	clear_textures(t_game *g)
{
	clear_sprite(&g->textures.left, g);
	clear_sprite(&g->textures.right, g);
	clear_sprite(&g->textures.down, g);
	clear_sprite(&g->textures.up, g);
	clear_sprite(&g->textures.mob, g);
	clear_sprite(&g->textures.collectible, g);
	mlx_destroy_image(g->mlx, g->textures.dead.ptr);
	clear_environment_textures(g);
	clear_numbers_textures(g);
}
