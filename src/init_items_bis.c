/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_items_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:37:28 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/13 23:53:54 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_perso(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (data->map.tab[y][x] != 'P' && y < data->map.height - 1)
	{
		x = 0;
		while (data->map.tab[y][x] != 'P' && x < data->map.width - 1)
			x++;
		y++;
	}
	data->perso.name = "user";
	data->perso.pos_x = x * TILESIZE;
	data->perso.pos_y = (y - 1) * TILESIZE;
	data->perso.img.file = "img/rayman_right.png";
	data->perso.img.width = TILESIZE;
	data->perso.img.height = TILESIZE;
	data->perso.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, \
	data->perso.img.file, &data->perso.img.width, &data->perso.img.height);
}

void	ft_init_dimension(t_data *data)
{
	int	width_pixel;
	int	height_pixel;

	width_pixel = TILESIZE * (data->map.width);
	height_pixel = TILESIZE * (data->map.height);
	data->win_ptr = mlx_new_window(data->mlx_ptr, width_pixel, \
	height_pixel, "My game");
}

void	ft_init_wall(t_data *data)
{
	data->wall.img.file = "img/wall48.png";
	data->wall.img.width = TILESIZE;
	data->wall.img.height = TILESIZE;
	data->wall.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, \
	data->wall.img.file, &data->wall.img.width, &data->wall.img.height);
}

void	ft_init_sky(t_data *data)
{
	data->sky.img.file = "img/sky.png";
	data->sky.img.width = TILESIZE;
	data->sky.img.height = TILESIZE;
	data->sky.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, \
	data->sky.img.file, &data->sky.img.width, &data->sky.img.height);
}

void	ft_init_collect(t_data *data)
{
	data->collect.img.file = "img/lumens/lumen48.png";
	data->collect.img.width = TILESIZE;
	data->collect.img.height = TILESIZE;
	data->collect.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, \
	data->collect.img.file, &data->collect.img.width, \
	&data->collect.img.height);
}
