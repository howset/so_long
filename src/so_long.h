/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:36:52 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/07/31 14:59:40 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h> //open
# include <X11/X.h> //keys
# include <X11/keysym.h> //keys
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/src/libft/libft.h"
# include "../lib/src/get_next_line/get_next_line.h"
# include "../lib/src/ft_printf/ft_printf.h"

/* # define WIN_HEIGHT 360
# define WIN_WIDTH 640
# define RED_PIXEL 0xFF0000
# define YELLOW_PIXEL 0xFFFF00
# define GREY_PIXEL 0x808080
# define PLAYER_XPM	"./assets/sprites/xpm/cow_front0.xpm" */

# define WALL				'1'
# define FLOO				'0'
# define COLL				'C'
# define PLAY				'P'
# define EXIT			 	'E'
# define SNEK			 	'S'

# define SPR_SIZE			64
# define XPM_WALL			"./assets/sprites/xpm/naturetile203.xpm"
# define XPM_FLOO			"./assets/sprites/xpm/floortile268.xpm"
# define XPM_PLAY_UP_0		"./assets/sprites/xpm/cgwalkup0.xpm"
# define XPM_PLAY_UP_1		"./assets/sprites/xpm/cgwalkup1.xpm"
# define XPM_PLAY_UP_2		"./assets/sprites/xpm/cgwalkup2.xpm"
# define XPM_PLAY_UP_3		"./assets/sprites/xpm/cgwalkup3.xpm"
# define XPM_PLAY_DOWN_0	"./assets/sprites/xpm/cgwalkdown0.xpm"
# define XPM_PLAY_DOWN_1	"./assets/sprites/xpm/cgwalkdown1.xpm"
# define XPM_PLAY_DOWN_2	"./assets/sprites/xpm/cgwalkdown2.xpm"
# define XPM_PLAY_DOWN_3	"./assets/sprites/xpm/cgwalkdown3.xpm"
# define XPM_PLAY_LEFT_0	"./assets/sprites/xpm/cgwalkleft0.xpm"
# define XPM_PLAY_LEFT_1	"./assets/sprites/xpm/cgwalkleft1.xpm"
# define XPM_PLAY_LEFT_2	"./assets/sprites/xpm/cgwalkleft2.xpm"
# define XPM_PLAY_LEFT_3	"./assets/sprites/xpm/cgwalkleft3.xpm"
# define XPM_PLAY_RIGHT_0	"./assets/sprites/xpm/cgwalkright0.xpm"
# define XPM_PLAY_RIGHT_1	"./assets/sprites/xpm/cgwalkright1.xpm"
# define XPM_PLAY_RIGHT_2	"./assets/sprites/xpm/cgwalkright2.xpm"
# define XPM_PLAY_RIGHT_3	"./assets/sprites/xpm/cgwalkright3.xpm"
# define XPM_PLAY_WIN		"./assets/sprites/xpm/cgitem.xpm"
# define XPM_PLAY_DEAD		"./assets/sprites/xpm/cgdead.xpm"
# define XPM_COLL_0			"./assets/sprites/xpm/cowfront0.xpm"
# define XPM_COLL_1			"./assets/sprites/xpm/cowfront1.xpm"
# define XPM_EXIT			"./assets/sprites/xpm/exit.xpm"
# define XPM_SNEK_0			"./assets/sprites/xpm/snakeright0.xpm"
# define XPM_SNEK_1			"./assets/sprites/xpm/snakeright1.xpm"
# define XPM_SNEK_2			"./assets/sprites/xpm/snakeright2.xpm"
# define XPM_SNEK_3			"./assets/sprites/xpm/snakeright3.xpm"

typedef struct	s_img {
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mapd
{
	char	**map;
	int		maprows;
	int		mapcols;
	int		coll_check;
	int		exit_check;
	int		play_check;
	int		p_pos_x;
	int 	p_pos_y;
}	t_mapd;

typedef struct s_sprite
{
	void	*wall;
	void	*floo;
	void	*coll;
	void	*exit;
	void	*play;
	void	*snek;
}	t_sprite;

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	//void		*textures[5]; // MLX image pointers (on the stack)
	t_mapd		map_details; // Map pointer (contains map details - preferably kept on the stack)
	t_sprite	sprites;
	int			spr_size;
	int			movement;
	//t_img	img; //temp, ab blog
}	t_data;

void	check_args(int argc, char *argv);
t_data	initialize_gdata(t_data *gdata);
void	initialize_mlx(t_data *gdata);
void	quit_message(t_data *gdata, char *error_msg);
void	map_load(char *ber_file, t_data *gdata);
int		read_ber(char *ber_file);
int		fill_map(char *ber_file, t_data *gdata);
void	load_xpm(t_data *gdata);
int		render_xpm(t_data *gdata);
void	rendering(t_data *gdata);
int		key_press(int keysym, t_data *gdata);
int		key_release(int keysym, t_data *gdata);
int		on_quit(t_data *gdata);
void 	on_destroy(t_data *gdata);
void	remove_xpm(t_data *gdata);
void	remove_map(t_data *gdata);
void	run_mlx(t_data *gdata);
void	background_layer(t_data *gdata);
void	update_player_pos(t_data *gdata, int horizontal, int length);
void	player_spr(t_data *gdata);
void	gather_elements(t_data *gdata);
void	check_elements(t_data *gdata);
#endif
