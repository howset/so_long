/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:21:17 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/01 19:53:31 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	increment_frame(t_data *gdata)
{
	int	i;
	int	j;

	gdata->frame = (gdata->frame + 1) % 4;
	//put_player(gdata, gdata->x, gdata->y);
	i = 0;
	while (gdata->map_details.map[i] != NULL)
	{
		j = 0;
		while (gdata->map_details.map[i][j])
		{
			if (gdata->map_details.map[i][j] == 'S')
				snek_animate(gdata, j, i);
			j++;
		}
		i++;
	}
	usleep(270000);
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

void	load_snek(t_data *gdata)
{
	gdata->sprites.snek0 = mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_SNEK_0, &gdata->spr_size, &gdata->spr_size);
	gdata->sprites.snek1 = mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_SNEK_1, &gdata->spr_size, &gdata->spr_size);
	gdata->sprites.snek2 = mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_SNEK_2, &gdata->spr_size, &gdata->spr_size);
	gdata->sprites.snek3 = mlx_xpm_file_to_image(gdata->mlx_ptr, XPM_SNEK_3, &gdata->spr_size, &gdata->spr_size);
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