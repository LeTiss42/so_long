/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:11:53 by mravera           #+#    #+#             */
/*   Updated: 2022/10/19 13:43:13 by mravera          ###   ########.fr       */
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


//keycode for MAC
# define ESC 53
# define ARROWUP 126
# define ARROWDOWN 125
# define ARROWLEFT 123
# define ARROWRIGHT 124
# define W 13
# define A 0
# define S 1
# define D 2

/*
//keycode for Ubuntu
# define ESC 65307
# define ARROWUP 65362
# define ARROWDOWN 65364
# define ARROWLEFT 65361
# define ARROWRIGHT 65363
# define W 119
# define A 97
# define S 115
# define D 100
*/

typedef struct s_img
{
	void	*ptr;
	int		w;
	int		h;
}	t_img;

typedef struct s_sprites
{
	t_img	coin;
	t_img	player_left;
	t_img	player_right;
	t_img	door_closed;
	t_img	door_open;
	t_img	wall;
	t_img	floor;
}	t_sprites;

typedef struct s_game
{
	char		**map;
	int			size_x;
	int			size_y;
	int			tot_x;
	int			tot_y;
	int			c_cnt;
	int			e_cnt;
	int			p_cnt;
	int			d_s;
	int			p_s;
	int			p_x;
	int			p_y;
	int			next_mv;
	int			move_cnt;
	t_sprites	sprites;
}	t_game;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	t_game	*mlxgame;

}	t_mlx;

//sl_check_args
void	sl_check_args(t_game *game, int argc, char **argv);
void	sl_check_filename(char *filename);
void	sl_check_size_x(t_game *game, int fd);
void	sl_check_size_y(t_game *game, int fd);

//sl_parsing
void	sl_parsing(t_game *game, char **argv);
void	sl_check_rectangle(t_game *game);
void	sl_check_char(t_game *game);
void	sl_check_cnt(t_game *game);
void	sl_check_close(t_game *game);

//sl_key_press
int		sl_key_press(int keycode, t_mlx *mlx);
int		sl_show_keycode(int keycode);

//sl_init_game
void	sl_init_game(t_mlx *mlx, t_game *game);
void	sl_init_images(t_mlx *mlx, t_game *game);
void	sl_init_player_door(t_mlx *mlx, t_game *game);
void	sl_check_sprites(t_game *game, t_mlx *mlx);
void	sl_destroy_images(t_game *game, t_mlx *mlx);

//sl_render_next_frame
int		sl_render_next_frame(t_mlx *mlx);
void	sl_render_walls(t_mlx *mlx);
void	sl_render_door(t_mlx *mlx);
void	sl_render_player(t_mlx *mlx);
void	sl_render_floor(t_mlx *mlx);

//sl_check_moves
int		sl_checkmoves(t_mlx *mlx);
void	sl_get_player_pos(t_mlx *mlx);
void	sl_check_status(t_mlx *mlx);

//sl_moves
void	sl_move_up(t_mlx *mlx);
void	sl_move_down(t_mlx *mlx);
void	sl_move_left(t_mlx *mlx);
void	sl_move_right(t_mlx *mlx);

//utils
void	sl_exit_nofree(char *text);
void	sl_exit_free_map(t_game *game, char *text);
void	sl_perror(char *text);
int		sl_close_free_map(t_game *game);
int		sl_close_all(t_mlx *mlx);

#endif