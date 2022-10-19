/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:06:29 by mravera           #+#    #+#             */
/*   Updated: 2022/10/19 19:01:12 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_check_path(t_game *game)
{
	char			**temp;
	int				x;
	int				y;

	x = 0;
	y = 0;
	game->c_check = 0;
	game->e_check = 0;
	temp = sl_dup_map(game);
	sl_display_tab(temp);
	while (temp[y] && temp[y][x] != 'P')
	{
		x = 0;
		y++;
		while (temp[y][x] && temp[y][x] != 'P')
			x ++;
	}
	ft_printf("x = %d\ny = %d\n", x, y);
	sl_flood(temp, x, y, game);
	ft_printf("coin %d\n     %d\n\nexit %d\n     %d\n", game->c_check, game->c_cnt, game->e_check, game->e_cnt);
	if (game->c_check != game->c_cnt || game->e_check != game->e_cnt)
		sl_exit_free_map(game, "Error\nThis map seems impossible.\n");
	sl_free_dup(temp);
	return ;
}

char	**sl_dup_map(t_game *game)
{
	char	**res;
	char	*temp;
	int		y;

	y = 0;
	while (game->map[y])
	{
		y ++;
	}
	res = ft_calloc(y + 1, sizeof(char *));
	y = 0;
	while (game->map[y])
	{
		temp = ft_strdup(game->map[y]);
		res[y] = temp;
		y ++;
	}
	return (res);
}

void	sl_free_dup(char **dup)
{
	int	x;

	x = 0;
	while (dup[x])
	{
		free(dup[x]);
		x ++;
	}
	free (dup);
	return ;
}

void	sl_flood(char **grid, int i, int j, t_game *game)
{
	int				x;
	int				y;

	if (grid[j][i] == 'C')
		game->c_check ++;
	if (grid[j][i] == 'E')
		game->e_check = 1;
	y = game->size_y;
	x = game->size_x;
	if (i < 0 || i >= x || j < 0 || j >= y || grid[j][i] == '1'
			|| grid[j][i] == 'X' || grid[j][i] == 'E')
		return ;
	grid[j][i] = 'X';
	sl_display_tab(grid);
	sl_flood(grid, i, j + 1, game);
	sl_flood(grid, i, j - 1, game);
	sl_flood(grid, i + 1, j, game);
	sl_flood(grid, i - 1, j, game);
	return ;
}

void	sl_display_tab(char **tab)
{
	int	x;

	x = 0;
	ft_printf("\n");
	while (tab[x])
		ft_printf("%s", tab[x++]);
	ft_printf("\n");
	return ;
}
