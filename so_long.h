/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:11:53 by mravera           #+#    #+#             */
/*   Updated: 2022/10/15 19:10:43 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "mlx/mlx.h"
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

//sl_check_args
void	sl_check_args(t_game *game, int argc, char **argv);
void	sl_check_filename(char *filename);
void	sl_check_size_x(t_game *game, int fd);
void	sl_check_size_y(t_game *game, int fd);

//sl_parsing
void	sl_parsing(t_game *game, char **argv);
void	sl_check_rectangle(t_game *game);

//utils
void	sl_exit_nofree(char *text);
void	sl_exit_free_map(t_game *game, char *text);
void	sl_perror(char *text);
int		ft_close(void);

#endif