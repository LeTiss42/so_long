/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:58:16 by mravera           #+#    #+#             */
/*   Updated: 2022/10/19 19:38:07 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_render_next_frame(t_mlx *mlx)
{
	char	*c;
	int		x;
	int		y;

	c = ft_itoa(mlx->mlxgame->move_cnt);
	sl_get_player_pos(mlx);
	x = mlx->mlxgame->p_x * 64 + 25;
	y = mlx->mlxgame->p_y * 64 + 12;
	sl_check_status(mlx);
	sl_render_floor(mlx);
	sl_render_player(mlx);
	sl_render_walls(mlx);
	sl_render_door(mlx);
	mlx_string_put(mlx->ptr, mlx->win, x, y, 0x00FF0000, c);
	free(c);
	return (1);
}

void	sl_render_walls(t_mlx *mlx)
{
	int		x;
	int		y;
	void	*wall_img;
	void	*coin_img;

	x = 0;
	y = 0;
	wall_img = mlx->mlxgame->sprites.wall.ptr;
	coin_img = mlx->mlxgame->sprites.coin.ptr;
	while (mlx->mlxgame->map[y])
	{
		while (mlx->mlxgame->map[y][x])
		{
			if (mlx->mlxgame->map[y][x] == '1')
				mlx_put_image_to_window(mlx->ptr, mlx->win, wall_img,
					x * 64, y * 64);
			else if (mlx->mlxgame->map[y][x] == 'C')
				mlx_put_image_to_window(mlx->ptr, mlx->win, coin_img,
					x * 64, y * 64);
		x ++;
		}
	x = 0;
	y++;
	}
	return ;
}

void	sl_render_door(t_mlx *mlx)
{
	int		x;
	int		y;
	void	*door_o_img;
	void	*door_c_img;

	x = 0;
	y = 0;
	door_o_img = mlx->mlxgame->sprites.door_open.ptr;
	door_c_img = mlx->mlxgame->sprites.door_closed.ptr;
	while (mlx->mlxgame->map[y])
	{
		while (mlx->mlxgame->map[y][x])
		{
			if (mlx->mlxgame->map[y][x] == 'e')
				mlx_put_image_to_window(mlx->ptr, mlx->win, door_o_img,
					x * 64, y * 64);
			else if (mlx->mlxgame->map[y][x] == 'E')
				mlx_put_image_to_window(mlx->ptr, mlx->win, door_c_img,
					x * 64, y * 64);
		x ++;
		}
	x = 0;
	y++;
	}
	return ;
}

void	sl_render_player(t_mlx *mlx)
{
	int		x;
	int		y;
	void	*player_l;
	void	*player_r;

	x = 0;
	y = 0;
	player_l = mlx->mlxgame->sprites.player_left.ptr;
	player_r = mlx->mlxgame->sprites.player_right.ptr;
	while (mlx->mlxgame->map[y])
	{
		while (mlx->mlxgame->map[y][x])
		{
			if (mlx->mlxgame->map[y][x] == 'P' && mlx->mlxgame->p_s == 0)
				mlx_put_image_to_window(mlx->ptr, mlx->win, player_l,
					x * 64, y * 64);
			if (mlx->mlxgame->map[y][x] == 'P' && mlx->mlxgame->p_s == 1)
				mlx_put_image_to_window(mlx->ptr, mlx->win, player_r,
					x * 64, y * 64);
		x ++;
		}
	x = 0;
	y++;
	}
	return ;
}

void	sl_render_floor(t_mlx *mlx)
{
	int		x;
	int		y;
	void	*floor_image;

	x = 0;
	y = 0;
	floor_image = mlx->mlxgame->sprites.floor.ptr;
	while (mlx->mlxgame->map[y])
	{
		while (mlx->mlxgame->map[y][x])
		{
			if (mlx->mlxgame->map[y][x] == '0'
				|| mlx->mlxgame->map[y][x] == 'C'
				|| mlx->mlxgame->map[y][x] == 'P')
				mlx_put_image_to_window(mlx->ptr, mlx->win, floor_image,
					x * 64, y * 64);
		x ++;
		}
	x = 0;
	y++;
	}
	return ;
}
