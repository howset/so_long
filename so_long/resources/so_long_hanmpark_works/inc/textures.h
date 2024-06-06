/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:17:38 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 23:20:21 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

t_sprite	*newsprite(t_game *game, char *path);
t_sprite	*lastsprite(t_sprite *sprite);
void		addsprite(t_sprite **sprite, t_sprite *new);
t_sprite	*load_sprites(char *path, char c, t_game *game);
t_img		get_img(void *mlx_ptr, char *path);

void		assign_textures(t_game *game);
void		clear_textures(t_game *g);

#endif