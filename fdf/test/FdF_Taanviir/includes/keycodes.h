/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:17:16 by tanas             #+#    #+#             */
/*   Updated: 2023/02/26 20:26:42 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# if __APPLE__
#  define ESCAPE 53
#  define ARROW_LEFT 123
#  define ARROW_RIGHT 124
#  define ARROW_DOWN 125
#  define ARROW_UP 126
#  define KEY_Q 12
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_E 14
#  define KEY_T 17 // TOP VIEW
#  define KEY_I 34 // ISOMETRIC VIEW
#  define KEY_R 15 // RESET MAP
#  define NUMPAD_PLUS 69 // INCREASE ZOOM
#  define NUMPAD_MINUS 78 // DECREASE ZOOM
#  define PLUS 24 // INCREASE ZOOM
#  define MINUS 27 // DECREASE ZOOM
#  define MORE 43 // INCREASE Z
#  define LESS 47 // DECREASE Z

# elif __LINUX__
#  define ESCAPE 0xFF1B
#  define ARROW_LEFT 65361
#  define ARROW_UP 65362
#  define ARROW_RIGHT 65363
#  define ARROW_DOWN 65364
#  define KEY_Q 113
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_E 101
#  define KEY_T 116 // TOP VIEW
#  define KEY_I 105 // ISOMETRIC VIEW
#  define KEY_R 114 // RESET MAP
#  define NUMPAD_PLUS 65451 // INCREASE ZOOM
#  define NUMPAD_MINUS 65453 // DECREASE ZOOM
#  define PLUS 43 // INCREASE ZOOM
#  define MINUS 45 // DECREASE ZOOM
#  define MORE 46 // INCREASE Z
#  define LESS 44 // DECREASE Z

# endif

#endif