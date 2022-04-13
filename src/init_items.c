/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 04:44:31 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/13 23:53:03 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_exit(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (data->map.tab[y][x] != 'E' && y < data->map.height - 1)
	{
		x = 0;
		while (data->map.tab[y][x] != 'E' && x < data->map.width - 1)
			x++;
		y++;
	}
	data->exit.pos_x = x * TILESIZE;
	data->exit.pos_y = (y - 1) * TILESIZE;
	data->exit.img.file = "img/exit48.png";
	data->exit.img.width = TILESIZE;
	data->exit.img.height = TILESIZE;
	data->exit.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, \
	data->exit.img.file, &data->exit.img.width, &data->exit.img.height);
}

void	ft_init_end(t_data *data)
{
	data->end.img.file = "img/end.png";
	data->end.img.width = TILESIZE * 5;
	data->end.img.height = TILESIZE;
	data->end.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, \
	data->end.img.file, &data->end.img.width, &data->end.img.height);
}

void	ft_init_enemy(t_data *data)
{
	data->enemy.enemy1.img.file = "img/enemy1.png";
	data->enemy.enemy1.img.width = TILESIZE;
	data->enemy.enemy1.img.height = TILESIZE;
	data->enemy.enemy1.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, \
	data->enemy.enemy1.img.file, &data->enemy.enemy1.img.width, \
	&data->enemy.enemy1.img.height);
	data->enemy.enemy2.img.file = "img/enemy1.png";
	data->enemy.enemy2.img.width = TILESIZE;
	data->enemy.enemy2.img.height = TILESIZE;
	data->enemy.enemy2.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, \
	data->enemy.enemy2.img.file, &data->enemy.enemy2.img.width, \
	&data->enemy.enemy2.img.height);
	data->enemy.enemy3.img.file = "img/enemy1.png";
	data->enemy.enemy3.img.width = TILESIZE;
	data->enemy.enemy3.img.height = TILESIZE;
	data->enemy.enemy3.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, \
	data->enemy.enemy3.img.file, &data->enemy.enemy3.img.width, \
	&data->enemy.enemy3.img.height);
}

void	ft_init_items(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->count_move = 0;
	data->count_collect = 0;
	data->is_end = 0;
	ft_init_dimension(data);
	ft_init_sky(data);
	ft_init_perso(data);
	ft_init_collect(data);
	ft_init_exit(data);
	ft_init_wall(data);
	ft_init_font(data);
	ft_init_end(data);
	ft_init_enemy(data);
}
