/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:51:00 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 23:41:07 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"

/**
 * @brief Sets the game map from a file.
 *
 * @param file The file to read the map from.
 * @param game Pointer to the game structure.
 * @return Returns true on success, false on error.
 */
static bool	set_map(char const *file, t_game *game)
{
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (send_error(NULL, NULL, ERR_BER));
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		game->map[i] = tmp;
		tmp = get_next_line(fd);
		i++;
	}
	close(fd);
	if (*game->map == NULL)
		return (send_error(game->map, game->mobs, ERR_BER));
	return (true);
}

/**
 * @brief Initializes the game map.
 *
 * @param file The file to read the map from.
 * @param game Pointer to the game structure.
 * @return Returns true on success, false on error.
 */
bool	map_init(char const *file, t_game *game)
{
	char	*line;

	line = ft_strnstr(file, ".ber", ft_strlen(file));
	if (!line || ft_strncmp(line, file + ft_strlen(file) - 4, 4))
		return (send_error(NULL, NULL, ERR_BER));
	ft_memset(&game->content, 0, sizeof(t_cnt));
	game->size.y = ft_filelen(file);
	game->map = ft_calloc(game->size.y + 1, sizeof(char *));
	if (!game->map)
		return (send_error(NULL, NULL, ERR_MALLOC));
	return (set_map(file, game) && check_map(game->map, game) \
		&& mob_init(game));
}
