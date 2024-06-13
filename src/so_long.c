/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:28:53 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/06/13 19:31:03 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* int	main(int argc, char *argv[])
{
	// check args --> send to error check function, maybe in new file
	if (argc != 2)
		ft_putchar_fd("Invalid number of arguments.\n", 2);
	
	
	// check map --> together with check args? or not?
	// initialize window --> in a different file?
	
} */

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
}

void	render_background(t_img *img, int color)
{
    int	i;
    int	j;

    i = 0;
    while (i < WIN_HEIGHT)
    {
        j = 0;
        while (j < WIN_WIDTH)
            img_pix_put(img, j++, i, color);
        ++i;
    }
}

// int render_rect(t_img *img, t_rect rect)
// {
//     int	i;
//     int j;

//     i = rect.y;
//     while (i < rect.y + rect.height)
//     {
//         j = rect.x;
//         while (j < rect.x + rect.width)
//             img_pix_put(img, j++, i, rect.color);
//         ++i;
//     }
//     return (0);
// }

// int render_square(t_data *data)
// {
//     int x;
//     int y;

//     x = 50;
//     y = 50;
//     while (x < 100)
//     {
//         while(y < 100)
//         {
//         mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, RED_PIXEL);
//         y++;
//         }
//     y = 50;
//     x++;
//     }
// 	return (0);
// }

int	render_sprite(t_data *data, t_sprite *sprite)
{
	t_data *data;
	t_sprite *sprite;
	
	sprite.spr = mlx_xpm_file_to_image(data.mlx_ptr, PLAYER_XPM, &sprite.width, &sprite.height);
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
        return (1);
	render_background(&data->img, GREY_PIXEL);
    //render_rect(&data->img, (t_rect){WIN_WIDTH / 2, WIN_HEIGHT / 2,
            //100, 100, YELLOW_PIXEL});
    //render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
    return (0);
}


int	handle_keypress(int keysym, t_rect rect)
{
	if (keysym == XK_Up || keysym == XK_w)
		rect.y -= 10;
		//ft_printf("Keypress: %d, up\n", keysym);
	if (keysym == XK_Left || keysym == XK_a)
		rect.x -= 10;
		//ft_printf("Keypress: %d, left\n", keysym);
	if (keysym == XK_Down || keysym == XK_s)
		rect.y += 10;
		//ft_printf("Keypress: %d, down\n", keysym);
	if (keysym == XK_Right || keysym == XK_d)
		rect.x += 10;
		//ft_printf("Keypress: %d, right\n", keysym);
	ft_printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	ft_printf("Keyrelease: %d\n", keysym);
	return (0);
}

int	main(void)
{
	t_data	data;
	//t_sprite	sprite;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Testing keypresses and releases");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (1);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); 
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}

/* int main(void)
{
    void *mlx; // The magical mlx pointer
    void *win; // The window pointer
    void *img; // The sprite image pointer
    int width; // Width of the sprite
    int height; // Height of the sprite
    int frame = 1; // Current frame of the sprite animation

    // Initialize mlx
    mlx = mlx_init();

    // Create a window
    win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Sprite Animation Ritual");

    // The animation loop
    while (1) {
        // Load the current frame of your sprite animation
        char frame_filename[100]; // Assuming frame filenames are like "frame1.xpm", "frame2.xpm", etc.
        sprintf(frame_filename, PLAYER_XPM);
        img = mlx_xpm_file_to_image(mlx, frame_filename, &width, &height);

        // Display the sprite on the window
        mlx_put_image_to_window(mlx, win, img, 100, 100);

        // Update the frame for the next iteration
        frame = (frame % 4) + 1; // Change frame from 1 to NUM_FRAMES and loop back

        // Adjust the frame rate for your desired animation speed
        usleep(100000); // Sleep for 0.1 seconds (adjust as needed)
    }

    return 0;
} */