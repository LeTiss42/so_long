/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:21:16 by mravera           #+#    #+#             */
/*   Updated: 2022/10/12 23:50:12 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(void)
{
	exit(0);
}

void	sl_parsing(t_game *game, int argc, char **argv)
{
	int		fd;
	char	*buffer;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer != NULL)
	{
		game->map[i] = malloc((ft_strlen(buffer) + 1) * sizeof(char));
		ft_strlcpy(game->map[i], buffer, ft_strlen(buffer + 1));
		buffer = get_next_line(fd);
		i++;
	}
}

void	sl_printftab(t_game game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game.map[i] != NULL)
		ft_printf(game.map[i++]);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	img;
	t_game	game;
	char	*line;
	int		fd1;

	if (argc != 2)
		return (0);
	sl_parsing(&game, argc, argv);
	mlx.ptr = mlx_init();
	if (mlx.ptr == NULL)
		return (EXIT_FAILURE);
	mlx.win = mlx_new_window(mlx.ptr, 640, 480, "Hello world");
	if (mlx.win == NULL)
		return (EXIT_FAILURE);
	mlx_hook(mlx.win, 17, 0, ft_close, 0);
	img.ptr = mlx_xpm_file_to_image(mlx.ptr, "floor6464.xpm", &img.l, &img.h);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 0, 0);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 64, 0);
	mlx_loop(mlx.ptr);
	return (EXIT_SUCCESS);
}
