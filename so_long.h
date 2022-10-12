/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:11:53 by mravera           #+#    #+#             */
/*   Updated: 2022/10/12 23:53:30 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>
# include "Libft/libft.h"

typedef struct s_mlx
{
	void	*ptr;
	void	*win;

}	t_mlx;

typedef struct s_img
{
	void	*ptr;
	void	*pxl_ptr;
	int		bpp;
	int		lsize;
	int		endian;
	int		h;
	int		l;
}	t_img;

typedef struct s_game
{
	char	**map;
	int		x;
	int		y;
}	t_game;

#endif