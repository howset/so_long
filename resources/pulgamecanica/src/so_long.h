/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:36:52 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/06/14 16:08:45 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/src/libft/libft.h"
# include "../lib/src/get_next_line/get_next_line.h"
# include "../lib/src/ft_printf/ft_printf.h"
//# include <mlx.h>
# include <sys/time.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
}		t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

enum entity {
	PLAYER,
	ENEMY,
	EVENT,
	OBJ,
	ANIMAL,
};

typedef struct s_animation {
	t_list *		frames;
	int				width;
	int				height;
	int				delay; // How many fps it takes to change animation
	int				_tmp_delay; // Delay Iterator
	int				current_frame_num; // Which frame is selected
	int				mirrored;
	long int		updated_at; // When was the last update
	long int		frame_count; // The frame count
	enum entity		entity;
	char *			name;
}		t_animation;

typedef enum e_bool {
	false,
	true
}	t_bool;

typedef struct s_ent {
	t_list * animations;
	int selected_animation;
	int	x;
	int y;
	int width;
	int height;
	enum entity entity;
}	t_ent;

typedef struct s_actions {
	t_bool	key_up;	// UP Arrow or W
	t_bool	key_down;	// DOWN Arroy or S
	t_bool	key_left; 	// KEY_W Arrow or A
	t_bool	key_right;	// KEY_S Arrow or d
	t_bool	key_space;	// KEY_SPACE
	t_bool	key_p;	// KEY_P
}		t_actions;

typedef struct s_game {
	t_list *	ents;
	t_actions	actions;
	uint64_t	created_at;
	uint64_t	updated_at;
	long int	frame_count;
	int	fps;
	int	selected_ent;
	t_bool looking_east;
	t_img	bg;
	t_img	game_img;
	t_win	win;
}		t_game;

typedef struct s_sprite {
	t_list	* animations;
	char	* name;
	char	* file_path;
	t_img	sprite_img;
	int	width;
	int	height;
	int	z_index;
}		t_sprite;

typedef	struct sprite_slice {
	int x;
	int y;
	int width;
	int height;
}	sprite_slice;

typedef struct parsed_slice {
	sprite_slice	slice;
	char *			name;
	unsigned int	frames;
	unsigned int	delay;
}	parsed_slice;

void	destroy_animation(void * ptr);
/* Game */
t_ent * new_ent(t_list * a, int x, int y, int width, int height, enum entity e);
void	destroy_game(t_game * game);
/* Utils */
uint64_t	gettimeofday_ms(void);
uint64_t	timestamp_in_ms(t_game * game);
int			key_released(int key_released, void *param);
int			key_pressed(int key_released, void *param);
void		update_ent(void * ptr1, void * ptr2);
void		add_ent_from_file_to_game(t_game * game, char * path);
void		update_animaiton(t_animation * a, t_ent * ent, t_img game_img);
int			ft_exit(t_game * g);
/* Sprite */
t_sprite		new_sprite(char * name, char * file_path, t_win * win);
//t_animation *	slice_sprite(t_sprite s, sprite_slice slice, int mirrored, int frames, int delay, enum entity e, char * name);
t_animation *	slice_sprite(t_sprite s, sprite_slice slice, int frames, int delay, enum entity e);
t_sprite *		load_file_sprite(t_win * win, char * path);
void			destroy_sprite(t_sprite s);
/*Window and Images*/
t_win	new_window(int w, int h, char *str);
t_img	new_file_img(char * path, t_win window);
t_img	new_img(int w, int h, t_win window);
unsigned int	get_pixel_img(t_img img, int x, int y);
void	put_pixel_img(t_img img, int x, int y, int color);
void	put_img_to_img(t_img dst, t_img src, int x, int y);
void	destroy_image(t_img img);
void	destroy_window(t_win w);
void	free_list(char ** list);
int		ft_list_size(char ** list);
char *	get_next_line_nl(int fd);
#endif
