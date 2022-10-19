/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:55:58 by mravera           #+#    #+#             */
/*   Updated: 2022/10/19 17:04:33 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_move_up(t_mlx *mlx)
{
	mlx->mlxgame->next_mv = W;
	if (sl_checkmoves(mlx) == 1)
	{
		mlx->mlxgame->p_y --;
		if (mlx->mlxgame->map[mlx->mlxgame->p_y][mlx->mlxgame->p_x]
			== 'C')
			mlx->mlxgame->c_cnt --;
		if (mlx->mlxgame->map[mlx->mlxgame->p_y][mlx->mlxgame->p_x]
			== 'e')
			sl_close_all(mlx);
		mlx->mlxgame->map[mlx->mlxgame->p_y + 1][mlx->mlxgame->p_x] = '0';
		mlx->mlxgame->map[mlx->mlxgame->p_y][mlx->mlxgame->p_x] = 'P';
		mlx->mlxgame->move_cnt ++;
		ft_printf("Nombre de mouvements = %d || Pieces manquantes = %d\n",
			mlx->mlxgame->move_cnt, mlx->mlxgame->c_cnt);
	}
	mlx->mlxgame->next_mv = 0;
}

void	sl_move_down(t_mlx *mlx)
{
	mlx->mlxgame->next_mv = S;
	if (sl_checkmoves(mlx) == 1)
	{
		mlx->mlxgame->p_y ++;
		if (mlx->mlxgame->map[mlx->mlxgame->p_y][mlx->mlxgame->p_x]
			== 'C')
			mlx->mlxgame->c_cnt --;
		if (mlx->mlxgame->map[mlx->mlxgame->p_y][mlx->mlxgame->p_x]
			== 'e')
			sl_close_all(mlx);
		mlx->mlxgame->map[mlx->mlxgame->p_y - 1][mlx->mlxgame->p_x] = '0';
		mlx->mlxgame->map[mlx->mlxgame->p_y][mlx->mlxgame->p_x] = 'P';
		mlx->mlxgame->move_cnt ++;
		ft_printf("Nombre de mouvements = %d || Pieces manquantes = %d\n",
			mlx->mlxgame->move_cnt, mlx->mlxgame->c_cnt);
	}
	mlx->mlxgame->next_mv = 0;
}

void	sl_move_left(t_mlx *mlx)
{
	mlx->mlxgame->next_mv = A;
	if (sl_checkmoves(mlx) == 1)
	{
		mlx->mlxgame->p_x --;
		if (mlx->mlxgame->map[mlx->mlxgame->p_y][mlx->mlxgame->p_x]
			== 'C')
			mlx->mlxgame->c_cnt --;
		if (mlx->mlxgame->map[mlx->mlxgame->p_y][mlx->mlxgame->p_x]
			== 'e')
			sl_close_all(mlx);
		mlx->mlxgame->map[mlx->mlxgame->p_y][mlx->mlxgame->p_x + 1] = '0';
		mlx->mlxgame->map[mlx->mlxgame->p_y][mlx->mlxgame->p_x] = 'P';
		mlx->mlxgame->p_s = 0;
		mlx->mlxgame->move_cnt ++;
		ft_printf("Nombre de mouvements = %d || Pieces manquantes = %d\n",
			mlx->mlxgame->move_cnt, mlx->mlxgame->c_cnt);
	}
	mlx->mlxgame->next_mv = 0;
}

void	sl_move_right(t_mlx *mlx)
{
	mlx->mlxgame->next_mv = D;
	if (sl_checkmoves(mlx) == 1)
	{
		mlx->mlxgame->p_x ++;
		if (mlx->mlxgame->map[mlx->mlxgame->p_y][mlx->mlxgame->p_x]
			== 'C')
			mlx->mlxgame->c_cnt --;
		if (mlx->mlxgame->map[mlx->mlxgame->p_y][mlx->mlxgame->p_x]
			== 'e')
			sl_close_all(mlx);
		mlx->mlxgame->map[mlx->mlxgame->p_y][mlx->mlxgame->p_x - 1] = '0';
		mlx->mlxgame->map[mlx->mlxgame->p_y][mlx->mlxgame->p_x] = 'P';
		mlx->mlxgame->p_s = 1;
		mlx->mlxgame->move_cnt ++;
		ft_printf("Nombre de mouvements = %d || Pieces manquantes = %d\n",
			mlx->mlxgame->move_cnt, mlx->mlxgame->c_cnt);
	}
	mlx->mlxgame->next_mv = 0;
}
