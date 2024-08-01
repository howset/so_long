#include <stdio.h>
#include <stdlib.h>

// Position structure to hold coordinates
typedef struct {
    int x;
    int y;
} Position;

// Function to perform flood fill
void flood_fill(char **map, int x, int y, int width, int height, int *reachable_exit, int *collectibles_found) {
    // Base cases: out of bounds, wall, or already visited
    if (x < 0 || y < 0 || x >= width || y >= height || map[y][x] == '1' || map[y][x] == 'V') {
        return;
    }

    // Mark the cell as visited
    if (map[y][x] == 'E') {
        *reachable_exit = 1;
    }
    if (map[y][x] == 'C') {
        (*collectibles_found)++;
    }
    map[y][x] = 'V'; // V for visited

    // Recursive calls for all four directions
    flood_fill(map, x + 1, y, width, height, reachable_exit, collectibles_found);
    flood_fill(map, x - 1, y, width, height, reachable_exit, collectibles_found);
    flood_fill(map, x, y + 1, width, height, reachable_exit, collectibles_found);
    flood_fill(map, x, y - 1, width, height, reachable_exit, collectibles_found);
}

// Function to check if the map is solvable
int is_map_solvable(char **map, int width, int height) {
    Position player_start = {-1, -1}; // Initialize with invalid position
    int collectibles_count = 0;
    int reachable_exit = 0;
    int collectibles_found = 0;

    // Find the player start position and count collectibles
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (map[y][x] == 'P') {
                player_start.x = x;
                player_start.y = y;
            }
            if (map[y][x] == 'C') {
                collectibles_count++;
            }
        }
    }

    // Check if player start position was found
    if (player_start.x == -1 || player_start.y == -1) {
        fprintf(stderr, "Error: No player start position found.\n");
        return 0;
    }

    printf("Player start position: (%d, %d)\n", player_start.x, player_start.y);
    printf("Total collectibles: %d\n", collectibles_count);

    // Perform flood fill from the player's starting position
    flood_fill(map, player_start.x, player_start.y, width, height, &reachable_exit, &collectibles_found);

    printf("Collectibles found: %d\n", collectibles_found);
    printf("Exit reachable: %d\n", reachable_exit);

    // Check if all collectibles were found and the exit is reachable
    return (collectibles_found == collectibles_count && reachable_exit);
}

// Function to print the map (for debugging purposes)
void print_map(char **map, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            putchar(map[y][x]);
        }
        putchar('\n');
    }
}

// Example usage
int main() {
    // Example map (array of strings)
    char *map[] = {
        "11111",
        "1P0C1",
        "101C1",
        "10E01",
        "11111",
        NULL
    };

    int width = 5;
    int height = 5;

    // Print the map before flood fill
    printf("Map before flood fill:\n");
    print_map(map, width, height);

    if (is_map_solvable(map, width, height)) {
        printf("The map is solvable.\n");
    } else {
        printf("The map is not solvable.\n");
    }

    // Print the map after flood fill (for debugging purposes)
    printf("Map after flood fill:\n");
    print_map(map, width, height);

    return 0;
}
