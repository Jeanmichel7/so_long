/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:15:20 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/11 18:12:37 by jrasser          ###   ########.fr       */
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

int	main(void)
{
	t_data	data;
	t_img	img;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "title");
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_mouse_hook(data.win_ptr, deal_mouse, &data);

	data.img_ptr = mlx_new_image(data.mlx_ptr, 50, 50);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 50, 50);

	mlx_loop(data.mlx_ptr);
	return (0);
}
