/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:36:52 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/06/17 12:36:13 by hsetyamu         ###   ########.fr       */
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

# define WIN_WIDTH 640
# define WIN_HEIGHT 360
# define RED_PIXEL 0xFF0000
# define YELLOW_PIXEL 0xFFFF00
# define GREY_PIXEL 0x808080
# define PLAYER_XPM	"./assets/sprites/xpm/cow_front0.xpm"

# define SPR_HEIGHT			64
# define SPR_WIDTH			64
# define WALL				'1'
# define FLOO				'0'
# define COLL				'C'
# define PLAY				'P'
# define EXIT			 	'E'
# define SNEK			 	'S'

# define XPM_WALL			"./assets/sprites/xpm/nature_tile203.xpm"
# define XPM_FLOO			"./assets/sprites/xpm/floor_tile268.xpm"
# define XPM_PLAY_UP_0		"./assets/sprites/xpm/cg_walk_up0.xpm"
# define XPM_PLAY_UP_1		"./assets/sprites/xpm/cg_walk_up1.xpm"
# define XPM_PLAY_UP_2		"./assets/sprites/xpm/cg_walk_up2.xpm"
# define XPM_PLAY_UP_3		"./assets/sprites/xpm/cg_walk_up3.xpm"
# define XPM_PLAY_DOWN_0	"./assets/sprites/xpm/cg_walk_down0.xpm"
# define XPM_PLAY_DOWN_1	"./assets/sprites/xpm/cg_walk_down1.xpm"
# define XPM_PLAY_DOWN_2	"./assets/sprites/xpm/cg_walk_down2.xpm"
# define XPM_PLAY_DOWN_3	"./assets/sprites/xpm/cg_walk_down3.xpm"
# define XPM_PLAY_LEFT_0	"./assets/sprites/xpm/cg_walk_left0.xpm"
# define XPM_PLAY_LEFT_1	"./assets/sprites/xpm/cg_walk_left1.xpm"
# define XPM_PLAY_LEFT_2	"./assets/sprites/xpm/cg_walk_left2.xpm"
# define XPM_PLAY_LEFT_3	"./assets/sprites/xpm/cg_walk_left3.xpm"
# define XPM_PLAY_RIGHT_0	"./assets/sprites/xpm/cg_walk_right0.xpm"
# define XPM_PLAY_RIGHT_1	"./assets/sprites/xpm/cg_walk_right1.xpm"
# define XPM_PLAY_RIGHT_2	"./assets/sprites/xpm/cg_walk_right2.xpm"
# define XPM_PLAY_RIGHT_3	"./assets/sprites/xpm/cg_walk_right3.xpm"
# define XPM_PLAY_WIN		"./assets/sprites/xpm/cg_item.xpm"
# define XPM_PLAY_DEAD		"./assets/sprites/xpm/cg_dead.xpm"
# define XPM_COLL_0			"./assets/sprites/xpm/cow_front0.xpm"
# define XPM_COLL_1			"./assets/sprites/xpm/cow_front1.xpm"
# define XPM_EXIT			"./assets/sprites/xpm/firewood.xpm"
# define XPM_SNEK_0			"./assets/sprites/xpm/snake_right0.xpm"
# define XPM_SNEK_1			"./assets/sprites/xpm/snake_right1.xpm"
# define XPM_SNEK_2			"./assets/sprites/xpm/snake_right2.xpm"
# define XPM_SNEK_3			"./assets/sprites/xpm/snake_right3.xpm"

typedef struct s_img
{
    //t_win	win;
	void	*mlx_img;
    char	*addr;
    int		bpp; //bits per pixel
    int		line_len;
    int		endian;
	int		img_width;
	int		img_height;
}	t_img;
typedef struct s_sl
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	//void		*textures[5]; // MLX image pointers (on the stack)
	//t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
	int			win_width;
	int			win_height;
	//t_img		rect; //temp, ab blog
	t_img		bg;
}	t_sl;

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

typedef struct s_xpm
{
    int width;
    int height;
}	t_xpm;

//utils.c/
int on_destroy(t_sl *sl);
void	img_pix_put(t_img *img, int x, int y, int color);
//keys.c
int	handle_keypress(int keysym);
int	handle_keyrelease(int keysym, t_sl *sl);
//rendering.c
void	render_background(t_img *img, int color);
int render_rect(t_img *img, t_rect rect);
int	render_sprite(t_sl **sl, t_xpm xpm);
int	render(t_sl *sl);
//so_long.c
#endif