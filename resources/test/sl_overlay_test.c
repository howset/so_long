#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void    *mlx;
    void    *win;
    void    *base_img;
    void    *overlay_img;
} t_game;

int main() {
    t_game game;
    int width = 0, height = 0;

    game.mlx = mlx_init();
    if (!game.mlx) {
        fprintf(stderr, "Failed to initialize MiniLibX\n");
        return EXIT_FAILURE;
    }

    game.win = mlx_new_window(game.mlx, 800, 600, "Sprite Overlay");
    if (!game.win) {
        fprintf(stderr, "Failed to create window\n");
        return EXIT_FAILURE;
    }

    game.base_img = mlx_xpm_file_to_image(game.mlx, "base.xpm", &width, &height);
    if (!game.base_img) {
        fprintf(stderr, "Failed to load base image\n");
        return EXIT_FAILURE;
    }

    game.overlay_img = mlx_xpm_file_to_image(game.mlx, "overlay.xpm", &width, &height);
    if (!game.overlay_img) {
        fprintf(stderr, "Failed to load overlay image\n");
        return EXIT_FAILURE;
    }

    mlx_put_image_to_window(game.mlx, game.win, game.base_img, 100, 100);
    mlx_put_image_to_window(game.mlx, game.win, game.overlay_img, 100, 100);

    mlx_loop(game.mlx);

    // Clean up resources
    mlx_destroy_image(game.mlx, game.base_img);
    mlx_destroy_image(game.mlx, game.overlay_img);
    mlx_destroy_window(game.mlx, game.win);

    return EXIT_SUCCESS;
}

/*
 * cc -Wall -Werror -Wextra -I/minilibx-linux/ sl_overlay_test.c minilibx-linux/libmlx.a -L/minilibx-linux/ -lmlx -lXext -lX11 -lm -o overlay_test
 * */
