/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:15:20 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/11 22:01:57 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	deal_key(int key, t_data *data)
{
	ft_printf("%d\n", key);
	if (key == 65307)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		//mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

int	deal_mouse(int button, int x, int y, t_data *data)
{
	ft_printf("%d %d %d\n", button, x, y);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;
	t_img	enemy;

	fd = ft_open_map(argv);
	ft_check_arg(argc, argv, fd);

	enemy.file = "img/enemy1.png";
	enemy.width = 50;
	enemy.height = 50;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "My game");

	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_mouse_hook(data.win_ptr, deal_mouse, &data);

	data.img_ptr = mlx_png_file_to_image(data.mlx_ptr, enemy.file, &enemy.width, &enemy.height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 150, 150);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 100, 100);

	mlx_loop(data.mlx_ptr);
	return (0);
}
