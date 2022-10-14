/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:46:02 by mravera           #+#    #+#             */
/*   Updated: 2022/10/14 18:22:06 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_exit_nofree(char *text)
{
	write(2, text, ft_strlen(text) + 1);
	exit(EXIT_FAILURE);
}

void	sl_perror(char *text)
{
	perror(text);
	exit(EXIT_FAILURE);
}

int	ft_close(void)
{
	exit(0);
}
