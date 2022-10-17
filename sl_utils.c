/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:46:02 by mravera           #+#    #+#             */
/*   Updated: 2022/10/17 17:38:15 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_exit_nofree(char *text)
{
	write(2, text, ft_strlen(text) + 1);
	exit(EXIT_FAILURE);
}

void	sl_exit_free_map(t_game *game, char *text)
{
	int	x;

	x = 0;
	write(2, text, ft_strlen(text) + 1);
	while (x < game->size_y)
	{
		free(game->map[x]);
		game->map[x] = NULL;
		x++ ;
	}
	free(game->map);
	game->map = NULL;
	exit(EXIT_FAILURE);
}

void	sl_perror(char *text)
{
	perror(text);
	exit(EXIT_FAILURE);
}

int	sl_close(t_game *game)
{
	sl_close_free_map(game);
	exit(EXIT_SUCCESS);
}

int	sl_close_free_map(t_game *game)
{
	int	x;

	x = 0;
	ft_printf("Shutting down...\n");
	while (x < game ->size_y)
	{
		free(game->map[x]);
		game->map[x] = NULL;
		x ++;
	}
	free(game->map);
	game->map = NULL;
	exit(EXIT_SUCCESS);
	return (1);
}
