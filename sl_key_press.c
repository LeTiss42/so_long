/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:30:39 by mravera           #+#    #+#             */
/*   Updated: 2022/10/18 13:30:12 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		sl_close(game);
	return (1);
}

int	sl_show_keycode(int keycode)
{
	ft_printf("keycode = %d\n", keycode);
	return (1);
}
