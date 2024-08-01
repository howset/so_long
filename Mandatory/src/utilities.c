/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:21:17 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/08/01 16:58:05 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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