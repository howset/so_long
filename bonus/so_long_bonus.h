/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:36:52 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/01 19:53:37 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <string.h>
# include <stdbool.h> //bool
# include <fcntl.h> //open
# include <X11/X.h> //keys
# include <X11/keysym.h> //keys
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/src/libft/libft.h"
# include "../lib/src/get_next_line/get_next_line.h"
# include "../lib/src/ft_printf/ft_printf.h"

# define WALL				'1'
# define FLOO				'0'
# define COLL				'C'
# define PLAY				'P'
# define EXIT			 	'E'
# define SNEK			 	'S'

# define SPR_SIZE			64
# define XPM_WALL			"./assets/sprites/naturetile203.xpm"
# define XPM_FLOO			"./assets/sprites/floortile268.xpm"
# define XPM_PLAY_DOWN_0	"./assets/sprites/cgwalkdown0.xpm"
# define XPM_COLL_0			"./assets/sprites/food0.xpm"
# define XPM_EXIT			"./assets/sprites/house.xpm"
# define XPM_SNEK_0			"./assets/sprites/snakeright0.xpm"
# define XPM_SNEK_1			"./assets/sprites/snakeright1.xpm"
# define XPM_SNEK_2			"./assets/sprites/snakeright2.xpm"
# define XPM_SNEK_3			"./assets/sprites/snakeright3.xpm"
# define XPM_MOVE			"./assets/sprites/movementtile.xpm"

typedef struct s_mapd
{
	char	**map;
	int		maprows;
	int		mapcols;
	int		coll_check;
	int		exit_check;
	int		play_check;
	int		pl_pos_x;
	int		pl_pos_y;
	int		ex_pos_x;
	int		ex_pos_y;
	int		coll_ff;
}	t_mapd;

typedef struct s_sprite
{
	void	*wall;
	void	*floo;
	void	*coll;
	void	*exit;
	void	*play;
	void	*snek0;
	void	*snek1;
	void	*snek2;
	void	*snek3;
	void	*move;
}	t_sprite;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mapd		map_details;
	t_sprite	sprites;
	int			spr_size;
	int			movement;
	int			frame;
}	t_data;

//so_long.c
void	check_args(int argc, char *argv);
t_data	initialize_gdata(t_data *gdata);
//map_load.c
void	map_load(char *ber_file, t_data *gdata);
int		read_ber(char *ber_file);
int		fill_map(char *ber_file, t_data *gdata);
//map_check1.c
void	map_check_elements(t_data *gdata);
void	gather_elements(t_data *gdata);
void	map_check_form(t_data *gdata);
void	check_rectangle(t_data *gdata);
void	check_walls(t_data *gdata);
//map_check2.c
void	map_check_ff(t_data *gdata);
void	ex_pos(t_data *gdata);
void	pl_pos(t_data *gdata, int i, int *player_col, int *player_row);
void	flood_fill(t_data *gdata, int y, int x, int **visited);
int		validmove(t_data *gdata, int **visited, int y, int x);
//initrun_mlx.c
void	initialize_mlx(t_data *gdata);
void	run_mlx(t_data *gdata);
int		key_press(int keysym, t_data *gdata);
//render.c
void	rendering(t_data *gdata);
void	load_xpm(t_data *gdata);
int		render_xpm(t_data *gdata);
void	display_xpm(char *line, t_data *gdata, int lines);
void	pl_location(t_data *gdata, int i, int lines);
//player.c
void	update_pos(t_data *gdata, int horizontal, int length);
void	update_spr(t_data *gdata);
void	tile_check(t_data *gdata);
void	player_spr(t_data *gdata);
//terminate.c
void	quit_message(t_data *gdata, char *error_msg);
int		on_quit(t_data *gdata);
void	on_destroy(t_data *gdata);
void	remove_xpm(t_data *gdata);
void	remove_map(t_data *gdata);
//utilities.c
char	*remove_trailing(char *s1, char const *set);
void	free_visited(int **visited, t_data *gdata);
void	load_snek(t_data *gdata);
int		increment_frame(t_data *gdata);
//animate_bonus.c
void	snek_animate(t_data *gdata, int x, int y);
#endif
