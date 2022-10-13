/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:11:53 by mravera           #+#    #+#             */
/*   Updated: 2022/10/13 23:50:09 by mravera          ###   ########.fr       */
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
	int		size_x;
	int		size_y;
	int		tot_x;
	int		tot_y;
}	t_game;

//sl_parsing
void	check_size(t_game *game, char **argv);
void	sl_check_filename(char *filename);

//utils
void	sl_exit_nofree(char *text);
int		ft_close(void);

#endif