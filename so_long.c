/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:21:16 by mravera           #+#    #+#             */
/*   Updated: 2022/10/12 02:06:54 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(void)
{
	exit(0);
}

int	main(void)
{
	t_mlx	mlx;
	t_img	img;

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
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 2 * 64, 0);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 3 * 64, 0);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 0, 64);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 0, 2 * 64);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 0, 3 * 64);
	mlx_destroy_image(mlx.ptr, img.ptr);
	mlx_loop(mlx.ptr);
	return (EXIT_SUCCESS);
}
