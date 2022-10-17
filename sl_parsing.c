/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:43:12 by mravera           #+#    #+#             */
/*   Updated: 2022/10/17 15:12:00 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_parsing(t_game *game, char **argv)
{
	int	x;
	int	fd;

	x = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		sl_perror("Error\nCould not open the file.\n");
	game->map = ft_calloc(game->size_y + 1, sizeof(char *));
	while (x < game->size_y)
		game->map[x++] = get_next_line(fd);
	if (close(fd) == -1)
		perror("Error\nCould not close the file.\n");
	return ;
}

void	sl_check_rectangle(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (game->map[y])
	{
		while (game->map[y][x] != '\0' && game->map[y][x] != '\n')
		{
			i++ ;
			x++ ;
		}
		printf("game[%d] = %s\n", y, game->map[y]);
		if (i != game->size_x)
			sl_exit_free_map(game, "Error\nMap must be rectangular.\n");
		y++ ;
		printf("\nx = %d\ny = %d\ni = %d\ngame_size_y = %d\ngame_size_x = %d\n", x, y, i, game->size_y, game->size_x);
		x = 0;
		i = 0;
	}
	return ;
}
