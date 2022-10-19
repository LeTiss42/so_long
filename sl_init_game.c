/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:43:17 by mravera           #+#    #+#             */
/*   Updated: 2022/10/19 15:58:47 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_init_game(t_mlx *mlx, t_game *game)
{
	game->tot_x = 64 * game->size_x;
	game->tot_y = 64 * game->size_y;
	game->d_s = 0;
	game->p_s = 0;
	game->move_cnt = 0;
	game->next_mv = 0;
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		sl_exit_free_map(game, "Error\ncould not init mlx.\n");
	mlx->win = mlx_new_window(mlx->ptr, game->tot_x, game->tot_y,
			"so_long");
	if (mlx->win == NULL)
	{
		free(mlx->ptr);
		mlx->ptr = NULL;
		sl_exit_free_map(game, "Error\nCoud not create window.\n");
	}
	sl_init_images(mlx, game);
	return ;
}

void	sl_init_images(t_mlx *mlx, t_game *game)
{
	char	*floor;
	char	*wall;
	char	*coin;

	floor = "textures/floor.xpm";
	wall = "textures/walls6464.xpm";
	coin = "textures/coin6464.xpm";
	game->sprites.floor.ptr = mlx_xpm_file_to_image(mlx->ptr, floor,
			&game->sprites.floor.w, &game->sprites.floor.h);
	game->sprites.wall.ptr = mlx_xpm_file_to_image(mlx->ptr, wall,
			&game->sprites.wall.w, &game->sprites.wall.h);
	game->sprites.coin.ptr = mlx_xpm_file_to_image(mlx->ptr, coin,
			&game->sprites.coin.w, &game->sprites.coin.h);
	sl_init_player_door(mlx, game);
	sl_check_sprites(game, mlx);
	return ;
}

void	sl_init_player_door(t_mlx *mlx, t_game *game)
{
	char	*player_l;
	char	*player_r;
	char	*door_o;
	char	*door_c;

	player_l = "textures/robot_left6464.xpm";
	player_r = "textures/robot_right6464.xpm";
	door_o = "textures/door_open6464.xpm";
	door_c = "textures/door_closed6464.xpm";
	game->sprites.player_left.ptr = mlx_xpm_file_to_image(mlx->ptr, player_l,
			&game->sprites.player_left.w, &game->sprites.player_left.h);
	game->sprites.player_right.ptr = mlx_xpm_file_to_image(mlx->ptr, player_r,
			&game->sprites.player_right.w, &game->sprites.player_right.h);
	game->sprites.door_open.ptr = mlx_xpm_file_to_image(mlx->ptr, door_o,
			&game->sprites.door_open.w, &game->sprites.door_open.h);
	game->sprites.door_closed.ptr = mlx_xpm_file_to_image(mlx->ptr, door_c,
			&game->sprites.door_closed.w, &game->sprites.door_closed.h);
	return ;
}

void	sl_check_sprites(t_game *game, t_mlx *mlx)
{
	if (game->sprites.coin.ptr == NULL
		|| game->sprites.door_closed.ptr == NULL
		|| game->sprites.door_open.ptr == NULL
		|| game->sprites.floor.ptr == NULL
		|| game->sprites.player_left.ptr == NULL
		|| game->sprites.player_right.ptr == NULL
		|| game->sprites.wall.ptr == NULL)
		sl_close_all(mlx);
	return ;
}

void	sl_destroy_images(t_mlx *mlx)
{
	mlx_destroy_image(mlx, mlx->mlxgame->sprites.coin.ptr);
	mlx_destroy_image(mlx, mlx->mlxgame->sprites.player_left.ptr);
	mlx_destroy_image(mlx, mlx->mlxgame->sprites.player_right.ptr);
	mlx_destroy_image(mlx, mlx->mlxgame->sprites.door_closed.ptr);
	mlx_destroy_image(mlx, mlx->mlxgame->sprites.door_open.ptr);
	mlx_destroy_image(mlx, mlx->mlxgame->sprites.wall.ptr);
	mlx_destroy_image(mlx, mlx->mlxgame->sprites.floor.ptr);
	return ;
}
