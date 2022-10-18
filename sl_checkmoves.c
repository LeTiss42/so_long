/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_checkmoves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:38:14 by mravera           #+#    #+#             */
/*   Updated: 2022/10/19 01:08:38 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_checkmoves(t_mlx *mlx)
{
	int	x;
	int	y;

	x = mlx->mlxgame->p_x;
	y = mlx->mlxgame->p_y;
	if (x == 0 || y == 0 || x == mlx->mlxgame->size_x - 1
		|| y == mlx->mlxgame->size_y - 1)
		return (0);
	if (mlx->mlxgame->next_mv == W && (mlx->mlxgame->map[y - 1][x] == '1'
		|| mlx->mlxgame->map[y - 1][x] == 'E'))
		return (0);
	if (mlx->mlxgame->next_mv == S && (mlx->mlxgame->map[y + 1][x] == '1'
		|| mlx->mlxgame->map[y + 1][x] == 'E'))
		return (0);
	if (mlx->mlxgame->next_mv == A && (mlx->mlxgame->map[y][x - 1] == '1'
		|| mlx->mlxgame->map[y][x - 1] == 'E'))
		return (0);
	if (mlx->mlxgame->next_mv == D && (mlx->mlxgame->map[y][x + 1] == '1'
		|| mlx->mlxgame->map[y][x + 1] == 'E'))
		return (0);
	return (1);
}

void	sl_get_player_pos(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mlx->mlxgame->map[y])
	{
		while (mlx->mlxgame->map[y][x])
		{
			if (mlx->mlxgame->map[y][x] == 'P')
			{
				mlx->mlxgame->p_x = x;
				mlx->mlxgame->p_y = y;
			}
			x ++;
		}
		x = 0;
		y ++;
	}
}

void	sl_check_status(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (mlx->mlxgame->c_cnt == 0)
	{
		while (mlx->mlxgame->map[y])
		{
			while (mlx->mlxgame->map[y][x])
			{
				if (mlx->mlxgame->map[y][x] == 'E')
					mlx->mlxgame->map[y][x] = 'e';
				x ++;
			}
			x = 0;
			y ++;
		}
	}
}
