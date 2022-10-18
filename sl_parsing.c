/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:43:12 by mravera           #+#    #+#             */
/*   Updated: 2022/10/18 19:17:32 by mravera          ###   ########.fr       */
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
	sl_check_rectangle(game);
	sl_check_char(game);
	sl_check_cnt(game);
	sl_check_close(game);
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

void	sl_check_char(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->c_cnt = 0;
	game->p_cnt = 0;
	game->e_cnt = 0;
	while (game->map[y])
	{
		while (game->map[y][x] != '\0' && game->map[y][x] != '\n')
		{
			if (game->map[y][x] == 'C')
				game->c_cnt ++;
			else if (game->map[y][x] == 'E')
				game->e_cnt ++;
			else if (game->map[y][x] == 'P')
				game->p_cnt ++;
			else if (game->map[y][x] != '0' && game->map[y][x] != '1')
				sl_exit_free_map(game, "Error\nForbidden character in map.\n");
			x++;
		}
		x = 0;
		y++;
	}
}

void	sl_check_cnt(t_game *game)
{
	ft_printf("P = %d\nE = %d\nC = %d\n", game->p_cnt, game->e_cnt, game->c_cnt);
	if (game->p_cnt != 1)
		sl_exit_free_map(game, "Error\nNeed 1 player.\n");
	else if (game->e_cnt != 1)
		sl_exit_free_map(game, "Error\nNeed 1 exit.\n");
	else if (game->c_cnt < 1)
		sl_exit_free_map(game, "Error\nNeed at least 1 collectible\n");
}

void	sl_check_close(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if ((y == 0 || y == (game->size_y - 1))
				&& (game->map[y][x] != '1' && game->map[y][x] != '\n'))
				sl_exit_free_map(game, "Error\nNeed walls 1st and last line.\n");
			else if (game->map[y][0] != '1'
				|| game->map[y][game->size_x - 1] != '1')
				sl_exit_free_map(game, "Error\nNeed walls 1st and last col.\n");
		x ++;
		}
	x = 0;
	y ++;
	}
}
