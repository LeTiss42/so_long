/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:03:55 by mravera           #+#    #+#             */
/*   Updated: 2022/10/17 15:12:02 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_check_args(t_game *game, int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		sl_exit_nofree("Error\nNeed 1 argument\nUsage : './so_long /map.ber'\n");
	sl_check_filename(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		sl_perror("Error\nCould not open the file.\n");
	sl_check_size_x(game, fd);
	sl_check_size_y(game, fd);
	if (close(fd) == -1)
		perror("Error\nCould not close open file\n");
	return ;
}

void	sl_check_filename(char *filename)
{
	if (ft_strnstr(filename, ".ber", ft_strlen(filename)) == NULL)
		sl_exit_nofree("Error\nFile provided is not a .ber file.\n");
	return ;
}

void	sl_check_size_x(t_game *game, int fd)
{
	char	buffer[2];
	int		ret;

	game->size_x = 0;
	game->size_y = 0;
	ret = read(fd, buffer, 1);
	if (ret == 0)
		sl_exit_nofree("Error\nThe provided file seems empty.\n");
	game->size_y = 1;
	while (ret != 0 && buffer[0] != '\n')
	{
		if (ret == -1)
			sl_perror("Error\nread() error.\n");
		game->size_x ++;
		ret = read(fd, buffer, 1);
	}
	ft_printf("x = %d", game ->size_x);
	if (game->size_x < 3)
		sl_exit_nofree("Error\nMap's length should be at least 3 (line 1).\n");
	if (buffer[0] == '\n')
		game->size_y ++;
	return ;
}

void	sl_check_size_y(t_game *game, int fd)
{
	char	buffer[2];
	int		ret;

	ret = read(fd, buffer, 1);
	while (ret != 0)
	{
		if (ret == -1)
			sl_perror("Error\nread() error.\n");
		if (buffer[0] == '\n')
			game->size_y ++;
		ret = read(fd, buffer, 1);
	}
	ft_printf("y = %d\n", game->size_y);
	if (buffer[0] == '\n')
		game->size_y --;
	if (game->size_y < 3)
		sl_exit_nofree("Error\nMap's height should be at least 3.\n");
	return ;
}
