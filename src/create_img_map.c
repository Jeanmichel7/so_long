/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:48:01 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/13 23:30:11 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_create_img_map_exit(t_data *data, int i, int j)
{
	data->exit.pos_x = i * TILESIZE;
	data->exit.pos_y = j * TILESIZE;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->exit.img.ptr_img, i * TILESIZE, j * TILESIZE);
}

void	ft_create_img_map(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < data->map.height)
	{
		i = -1;
		while (++i < data->map.width)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->sky.img.ptr_img, i * TILESIZE, j * TILESIZE);
			if (data->map.tab[j][i] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
				data->wall.img.ptr_img, i * TILESIZE, j * TILESIZE);
			if (data->map.tab[j][i] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
				data->perso.img.ptr_img, i * TILESIZE, j * TILESIZE);
			if (data->map.tab[j][i] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
				data->collect.img.ptr_img, i * TILESIZE, j * TILESIZE);
			if (data->map.tab[j][i] == 'E')
				ft_create_img_map_exit(data, i, j);
		}
	}
}

void	ft_generate_enemy_display(t_data *data, int i, int j, int *nb_enemy)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->enemy.enemy1.img.ptr_img, i * TILESIZE, j * TILESIZE);
	data->map.tab[j][i] = 'X';
	*nb_enemy += 1;
}

void	ft_generate_enemy(t_data *data)
{
	int	i;
	int	j;
	int	k;
	int	coef;
	int	nb_enemy;

	coef = data->map.width - (data->map.width / 5);
	nb_enemy = 0;
	k = 0;
	j = -1;
	while (++j < data->map.height)
	{
		i = -1;
		while (++i < data->map.width)
		{
			if (data->map.tab[j][i] == '0')
			{
				if (k == coef * nb_enemy)
					ft_generate_enemy_display(data, i, j, &nb_enemy);
				k++;
			}
		}
	}
}
