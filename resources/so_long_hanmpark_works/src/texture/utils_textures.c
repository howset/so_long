/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:48:29 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 23:31:27 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "textures.h"

/**
 * @brief Creates a new sprite.
 *
 * @param game Pointer to the game structure.
 * @param path Path to the sprite image.
 * @return Returns a pointer to the new sprite.
 */
t_sprite	*newsprite(t_game *game, char *path)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	sprite->img = get_img(game->mlx, path);
	sprite->next = NULL;
	return (sprite);
}

/**
 * @brief Finds the last sprite in a linked list of sprites.
 *
 * @param sprite Pointer to the first sprite in the list.
 * @return Returns a pointer to the last sprite in the list.
 */
t_sprite	*lastsprite(t_sprite *sprite)
{
	if (!sprite)
		return (NULL);
	while (sprite->next)
		sprite = sprite->next;
	return (sprite);
}

/**
 * @brief Adds a new sprite to a linked list of sprites.
 *
 * @param sprite Pointer to the pointer to the first sprite in the list.
 * @param new Pointer to the new sprite to be added.
 */
void	addsprite(t_sprite **sprite, t_sprite *new)
{
	t_sprite	*last;

	if (!sprite || !new)
		return ;
	if (!*sprite)
	{
		*sprite = new;
		return ;
	}
	last = lastsprite(*sprite);
	last->next = new;
}

/**
 * @brief Loads a series of sprites.
 *
 * @param path Path to the sprite images.
 * @param c Number of sprites to load.
 * @param game Pointer to the game structure.
 * @return Returns a pointer to the first sprite in the list.
 */
t_sprite	*load_sprites(char *path, char c, t_game *game)
{
	t_sprite	*sprite;
	char		*pathdup;
	char		number;
	int			index;

	pathdup = ft_strdup(path);
	sprite = newsprite(game, pathdup);
	number = '1';
	index = 0;
	while (pathdup && pathdup[index] != '0')
		index++;
	while (number < c)
	{
		pathdup[index] = number;
		addsprite(&sprite, newsprite(game, pathdup));
		number++;
	}
	free(pathdup);
	return (sprite);
}

/**
 * @brief Loads an image.
 *
 * @param mlx_ptr Pointer to the mlx instance.
 * @param path Path to the image file.
 * @return Returns the loaded image.
 */
t_img	get_img(void *mlx_ptr, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx_ptr, path, &img.width, &img.height);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.line_len, &img.endian);
	return (img);
}
