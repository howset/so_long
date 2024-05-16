/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:15:03 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/07 10:53:46 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define FPS 40

long long	get_time(void);
int			update(t_game *game);

void		anim_enemy(t_game *game);
void		anim_player(t_game *game);
void		anim_collectible(t_game *game);

void		move_enemy(t_game *game);
void		move_player(t_game *game);

int			render(t_game *game);
void		render_map(t_game *game, t_img *buffer, t_pos pl);
void		put_image_to_buffer(t_img *buffer, t_img img, int x, int y);

#endif