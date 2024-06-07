/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:46:33 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 23:14:33 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# ifdef __APPLE__
#  define KEY_ESC			53
#  define KEY_L				0
#  define KEY_D				1
#  define KEY_R				2
#  define KEY_U				13
#  define KEY_SPACE			49
#  define KEYPRESS_MASK		0
#  define KEYRELEASE_MASK	0
# elif defined __unix__
#  define KEY_ESC			65307
#  define KEY_L				97
#  define KEY_D				115
#  define KEY_R				100
#  define KEY_U				119
#  define KEY_SPACE			32
#  define KEYPRESS_MASK		1L << 0
#  define KEYRELEASE_MASK	1L << 1
# endif

# define KEYPRESS 2
# define KEYRELEASE 3

int	key_pressed(int key, t_game *game);
int	key_released(int key, t_game *game);
int	game_close(t_game *game);

#endif
