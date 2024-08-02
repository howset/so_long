/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetya <hsetya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:21:17 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/01 23:12:46 by hsetya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//increment frame for animated sprites (player, cow, snek)
int	increment_frame(t_data *gdata)
{
	int	i;
	int	j;

	gdata->frame = (gdata->frame + 1) % 4;
	player_animate(gdata, gdata->map_details.pl_pos_x, \
	gdata->map_details.pl_pos_y);
	i = 0;
	while (gdata->map_details.map[i] != NULL)
	{
		j = 0;
		while (gdata->map_details.map[i][j])
		{
			if (gdata->map_details.map[i][j] == 'S')
				snek_animate(gdata, j, i);
			if (gdata->map_details.map[i][j] == 'C')
				cow_animate(gdata, j, i);
			j++;
		}
		i++;
	}
	usleep(150000);
	return (0);
}

//helper function for flood fill
void	free_visited(int **visited, t_data *gdata)
{
	int	i;

	i = 0;
	while (i < gdata->map_details.maprows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

//to remove trailing \n in map
char	*remove_trailing(char *c, char const *str)
{
	int		start;
	int		end;
	char	*trimmed;

	if (!c || !str)
		return (NULL);
	start = 0;
	while (c[start] != '\0' && ft_strchr(str, c[start]) != NULL)
		start++;
	end = ft_strlen(c + start);
	while (end > start && ft_strchr(str, c[(start + end) - 1]) != NULL)
		end--;
	trimmed = ft_calloc((end + 1), sizeof(char *));
	if (!trimmed)
		return (NULL);
	ft_strncpy(trimmed, (c + start), end);
	free(c);
	return (trimmed);
}

//helper to remove_xpm, because too long
void	remove_animated_xpm(t_data *gdata)
{
	if (gdata->sprites.coll0)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.coll0);
	if (gdata->sprites.coll1)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.coll1);
	if (gdata->sprites.play0)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.play0);
	if (gdata->sprites.play1)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.play1);
	if (gdata->sprites.play2)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.play2);
	if (gdata->sprites.play3)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.play3);
	if (gdata->sprites.snek0)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.snek0);
	if (gdata->sprites.snek1)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.snek1);
	if (gdata->sprites.snek2)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.snek2);
	if (gdata->sprites.snek3)
		mlx_destroy_image(gdata->mlx_ptr, gdata->sprites.snek3);
}

//check content of map
/* void print_2d_array(char **array) {
	int i = 0;
	while (array[i] != NULL) {
		int j = 0;
		while (array[i][j] != '\0') {
			ft_putchar_fd(array[i][j], 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
} */