#include <mlx.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define TILE_SIZE 32

typedef struct {
    void    *mlx;
    void    *win;
    void    *player_img;
    void    *wall_img;
    void    *collectible_img;
    void    *exit_img;
    char    **map;
    int     player_x;
    int     player_y;
    int     collectibles;
} t_game;

void    error_and_exit(char *message) {
    write(2, message, strlen(message));
    exit(1);
}

char    **load_map(char *filename, int *width, int *height) {
    int     fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_and_exit("Failed to open map file\n");

    char    **map = malloc(sizeof(char *) * 100); // Adjust the size as needed
    char    *line = NULL;
    size_t  len = 0;
    ssize_t read;
    int     y = 0;
    while ((read = getline(&line, &len, fdopen(fd, "r"))) != -1) {
        map[y] = strdup(line);
        *width = read > *width ? read : *width;
        y++;
    }
    *height = y;
    close(fd);
    return map;
}

void    draw_map(t_game *game) {
    for (int y = 0; game->map[y]; y++) {
        for (int x = 0; game->map[y][x]; x++) {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->collectible_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
        }
    }
    mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}

int     key_hook(int keycode, t_game *game) {
    if (keycode == 65307) // ESC key
        exit(0);
    int new_x = game->player_x;
    int new_y = game->player_y;
    if (keycode == 65361) // Left arrow
        new_x--;
    else if (keycode == 65362) // Up arrow
        new_y--;
    else if (keycode == 65363) // Right arrow
        new_x++;
    else if (keycode == 65364) // Down arrow
        new_y++;
    if (game->map[new_y][new_x] != '1') {
        game->player_x = new_x;
        game->player_y = new_y;
    }
    draw_map(game);
    return 0;
}

int     main(int argc, char **argv) {
    if (argc != 2)
        error_and_exit("Usage: ./my_game <map_file>\n");

    t_game game;
    int width = 0, height = 0;

    game.map = load_map(argv[1], &width, &height);
    game.player_x = 1;
    game.player_y = 1;
    game.collectibles = 0;

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, width * TILE_SIZE, height * TILE_SIZE, "So Long");
    game.player_img = mlx_xpm_file_to_image(game.mlx, "player.xpm", &width, &height);
    game.wall_img = mlx_xpm_file_to_image(game.mlx, "wall.xpm", &width, &height);
    game.collectible_img = mlx_xpm_file_to_image(game.mlx, "collectible.xpm", &width, &height);
    game.exit_img = mlx_xpm_file_to_image(game.mlx, "exit.xpm", &width, &height);

    draw_map(&game);
    mlx_key_hook(game.win, key_hook, &game);
    mlx_loop(game.mlx);

    return 0;
}
