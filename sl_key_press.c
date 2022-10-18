/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:30:39 by mravera           #+#    #+#             */
/*   Updated: 2022/10/19 00:49:01 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		sl_close_all(mlx);
	if (keycode == W)
		sl_move_up(mlx);
	if (keycode == S)
		sl_move_down(mlx);
	if (keycode == A)
		sl_move_left(mlx);
	if (keycode == D)
		sl_move_right(mlx);
	return (1);
}

int	sl_show_keycode(int keycode)
{
	ft_printf("keycode = %d\n", keycode);
	return (1);
}
