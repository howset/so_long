#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define TILE_SIZE 64

typedef struct {
    void *mlx;
    void *win;
    void *tile_img;
    int map_width;
    int map_height;
    char **map;
} t_game;

void load_images(t_game *game) {
    int width, height;
    game->tile_img = mlx_xpm_file_to_image(game->mlx, "base.xpm", &width, &height);
    if (!game->tile_img) {
        printf("Failed to load tile image.\n");
        exit(EXIT_FAILURE);
    }
}

void draw_map(t_game *game) {
    int y = 0;
    while (y < game->map_height) {
        int x = 0;
        while (x < game->map_width) {
            mlx_put_image_to_window(game->mlx, game->win, game->tile_img, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}

int main() {
    t_game game;

    // Initialize map dimensions
    game.map_width = 10;  // For example, 10 tiles wide
    game.map_height = 8;  // For example, 8 tiles high

    // Initialize MLX
    game.mlx = mlx_init();
    if (!game.mlx) {
        printf("Failed to initialize MLX.\n");
        return EXIT_FAILURE;
    }

    // Create a window
    game.win = mlx_new_window(game.mlx, game.map_width * TILE_SIZE, game.map_height * TILE_SIZE, "Tile Map");
    if (!game.win) {
        printf("Failed to create window.\n");
        return EXIT_FAILURE;
    }

    // Load images
    load_images(&game);

    // Draw the map
    draw_map(&game);

    // Enter the MLX event loop
    mlx_loop(game.mlx);

    return EXIT_SUCCESS;
}
