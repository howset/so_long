/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetya <hsetya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:28:53 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/06/18 12:53:17 by hsetya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	get_pixel_img(t_img img, int x, int y) {
	return (*(unsigned int *)((img.addr
			+ (y * img.line_len) + (x * img.bpp / 8))));
}

void	destroy_window(t_win w) {
	if (w.mlx_ptr && w.win_ptr)
		mlx_destroy_window(w.mlx_ptr, w.win_ptr);
	if (w.mlx_ptr)
		free(w.mlx_ptr);
}

void	destroy_image(t_img img) {
	if (img.img_ptr && img.win.mlx_ptr)
		mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
}

t_sprite	new_sprite(char * name, char/* int main(void)
{
    void *mlx; // The magical mlx pointer
    void *win; // The window pointer
    void *img; // The sprite image pointer
    int width; // Width of the sprite
    int height; // Height of the sprite
    int frame = 1; // Current frame of the sprite animation

    mlx = mlx_init(); // Initialize mlx
    win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Sprite Animation Ritual"); // Create a window

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
} */ * file_path, t_win * win) {
	t_img	img;

	img = new_file_img(file_path, *win);
	return (t_sprite){NULL, ft_strdup(name),
		ft_strdup(file_path), img, img.w, img.h, 0};
}

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	if (!(elem = malloc(sizeof(t_list))))
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (lst)
		while (tmp->next)
			tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			tmp = ft_lstlast(*(alst));
			tmp->next = new;
		}
	}
}


/* int main(void)
{
 	t_win	tutorial;
	t_img	image;
	
	tutorial = new_window(600, 500, "animations");
	if (!tutorial.win_ptr)
		return (2);
	image = new_img(600, 500, tutorial);
	{
		//Put white pixel
		put_pixel_img(image, 150, 150, 0x00FFFFFF);
		mlx_put_image_to_window (image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0, 0);
		destroy_image(image);
	}
	{
		//Put image
		t_img	tloz_img;
		tloz_img = new_file_img("assets/cow_front0.xpm", tutorial);
		if (!tloz_img.img_ptr)
			return (1);
		mlx_put_image_to_window (tloz_img.win.mlx_ptr, tloz_img.win.win_ptr, tloz_img.img_ptr, 0, 0);	
		destroy_image(tloz_img);
	}
	mlx_loop(tutorial.mlx_ptr);
	destroy_window(tutorial);
	return (0);
} */

t_win new_window(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h) {
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

t_img	new_file_img(char * path, t_win window) {
	t_img image;

	image.win = window;
	image.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, path, &image.w, &image.h);
	if (!image.img_ptr)
		write(2, "File could not be read\n", 23);
	else
		image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	return (image);
}

int main(void)
{
 	t_win	tutorial;
	t_img	image;
	t_img	tloz_img;
	
	tutorial = new_window(600, 500, "animations");
	if (!tutorial.win_ptr)
		return (2);

	/* Put white pixel */
	image = new_img(600, 500, tutorial);
	put_pixel_img(image, 150, 150, 0xFF0000);
	mlx_put_image_to_window (image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0, 0);
	destroy_image(image);

	/* Put image */
	tloz_img = new_file_img("assets/cow_front0.xpm", tutorial);
	if (!tloz_img.img_ptr)
		return (1);
	mlx_put_image_to_window (tloz_img.win.mlx_ptr, tloz_img.win.win_ptr, tloz_img.img_ptr, 0, 0);	
	destroy_image(tloz_img);

	mlx_loop(tutorial.mlx_ptr);
	destroy_window(tutorial);
	return (0);
}