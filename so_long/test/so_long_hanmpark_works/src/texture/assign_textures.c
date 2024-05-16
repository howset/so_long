/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 02:55:13 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 23:33:00 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "textures.h"

/**
 * @brief Assigns sprite textures.
 *
 * @param game Pointer to the game structure.
 */
static void	assign_sprites_textures(t_game *game)
{
	t_texture	*txt;

	txt = &game->textures;
	txt->down = load_sprites("./img/player/dir/down/down0.xpm", '4', game);
	txt->up = load_sprites("./img/player/dir/up/up0.xpm", '4', game);
	txt->left = load_sprites("./img/player/dir/left/left0.xpm", '4', game);
	txt->right = load_sprites("./img/player/dir/right/right0.xpm", '4', game);
	txt->current = game->textures.down;
	txt->current_back = game->textures.down;
	txt->dead = get_img(game->mlx, "./img/player/dead.xpm");
	txt->mob = load_sprites("./img/mob/mob0.xpm", '8', game);
	txt->mob_back = game->textures.mob;
	txt->collectible = load_sprites("./img/collectible/coin0.xpm", '7', game);
	txt->collectible_back = game->textures.collectible;
}

/**
 * @brief Assigns environment textures.
 *
 * @param game Pointer to the game structure.
 */
static void	assign_environment_textures(t_game *game)
{
	t_texture	*txt;

	txt = &game->textures;
	txt->wall = get_img(game->mlx, "./img/env/wall.xpm");
	txt->floor[0] = get_img(game->mlx, "./img/env/ground.xpm");
	txt->floor[1] = get_img(game->mlx, "./img/env/ground1.xpm");
	txt->floor[2] = get_img(game->mlx, "./img/env/ground2.xpm");
	txt->exit[0] = get_img(game->mlx, "./img/env/exit0.xpm");
	txt->exit[1] = get_img(game->mlx, "./img/env/exit1.xpm");
	txt->border[0] = get_img(game->mlx, "./img/border/border.xpm");
	txt->border[1] = get_img(game->mlx, "./img/border/border_go.xpm");
	txt->border[2] = get_img(game->mlx, "./img/border/border_lvl.xpm");
}

/**
 * @brief Assigns number textures.
 *
 * @param game Pointer to the game structure.
 */
static void	assign_numbers_textures(t_game *game)
{
	t_texture	*txt;

	txt = &game->textures;
	txt->number[0] = get_img(game->mlx, "./img/numbers/0.xpm");
	txt->number[1] = get_img(game->mlx, "./img/numbers/1.xpm");
	txt->number[2] = get_img(game->mlx, "./img/numbers/2.xpm");
	txt->number[3] = get_img(game->mlx, "./img/numbers/3.xpm");
	txt->number[4] = get_img(game->mlx, "./img/numbers/4.xpm");
	txt->number[5] = get_img(game->mlx, "./img/numbers/5.xpm");
	txt->number[6] = get_img(game->mlx, "./img/numbers/6.xpm");
	txt->number[7] = get_img(game->mlx, "./img/numbers/7.xpm");
	txt->number[8] = get_img(game->mlx, "./img/numbers/8.xpm");
	txt->number[9] = get_img(game->mlx, "./img/numbers/9.xpm");
}

/**
 * @brief Assigns all textures.
 *
 * @param game Pointer to the game structure.
 */
void	assign_textures(t_game *game)
{
	assign_sprites_textures(game);
	assign_environment_textures(game);
	assign_numbers_textures(game);
}
