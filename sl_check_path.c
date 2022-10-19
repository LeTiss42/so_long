/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:06:29 by mravera           #+#    #+#             */
/*   Updated: 2022/10/19 17:02:58 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_check_path(t_game *game)
{
	char	**temp;

	temp = sl_dup_map(game);
	sl_display_tab(temp);
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
