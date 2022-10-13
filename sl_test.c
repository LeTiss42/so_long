/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:06:09 by mravera           #+#    #+#             */
/*   Updated: 2022/10/13 23:48:40 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_check_filename(char *filename)
{
	if (ft_strnstr(filename, ".ber", ft_strlen(filename)) == NULL)
		sl_exit_nofree("Error, file provided is not a .ber file\n");
}

void	check_size(t_game *game, char **argv)
{
	int		fd;
	char	buffer[2];
	int		ret_val;
	int		x;

	x = 0;
	fd = open(argv[1], O_RDONLY);
	buffer[1] = '\0';
	ret_val = read(fd, buffer, 1);
	game->size_y = 1;
	game->size_x = 0;
	while (ret_val > 0)
	{
		if (buffer[0] != '\n')
			x ++;
		else
		{
			if (game->size_x != 0 && x != game->size_x)
				sl_exit_nofree("map is not rectangular\n");
			game->size_x = x;
			game->size_y ++;
			x = 0;
		}
	ret_val = read(fd, buffer, 1);
	}
}
