/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:21:16 by mravera           #+#    #+#             */
/*   Updated: 2022/10/19 00:34:30 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_game	game;
	int		i;

	i = 0;
	sl_check_args(&game, argc, argv);
	sl_parsing(&game, argv);
	while (i < game.size_y)
	{
		ft_printf("map[%d] = %p\n", i, game.map[i]);
		i++;
	}
	sl_init_game(&mlx, &game);
	mlx.mlxgame = &game;
	mlx_loop_hook(mlx.ptr, sl_render_next_frame, &mlx);
	mlx_hook(mlx.win, 17, 1L << 2, sl_close_all, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, sl_key_press, &mlx);
	mlx_loop(mlx.ptr);
	return (EXIT_SUCCESS);
}
