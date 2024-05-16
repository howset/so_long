/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:54:45 by tanas             #+#    #+#             */
/*   Updated: 2023/02/28 14:40:33 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define ERR_MSG "\033[1;3;31m\n Invalid file entered.\n \
Use \"fdf [map].fdf\" to run this program."

static void	check_file_type(char *file)
{
	char	*file_type;
	int		i;

	file_type = ft_strrchr(file, '.');
	if (!file_type)
	{
		ft_putendl_fd(ERR_MSG, 2);
		exit(0);
	}
	i = 0;
	while (file_type[i])
	{
		if (file_type[i + 1] == 'f')
			if (file_type[i + 2] == 'd')
				if (file_type[i + 3] == 'f')
					return ;
		ft_putendl_fd(ERR_MSG, 2);
		exit(0);
		i++;
	}
}

int	check_file(char *file, int count)
{
	int	fd;

	if (count != 2)
	{
		ft_putendl_fd("\033[1;3;31m\n .fdf file is missing.", 2);
		ft_putendl_fd("Use \"./fdf [map].fdf\" to run this program.", 2);
		exit (0);
	}
	check_file_type(file);
	fd = open(file, O_RDONLY);
	if (fd < 3)
	{
		close(fd);
		ft_putendl_fd(ERR_MSG, 2);
		exit (0);
	}
	close(fd);
	return (1);
}
