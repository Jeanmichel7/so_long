/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:48:01 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/12 21:02:57 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_create_img_map(t_data data)
{
	int i;
	int j;
	
	j = -1;
	while (++j < data.map.height)
	{
		i = -1;
		while (++i < data.map.width)
		{
			mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
				data.sky.img.ptr_img, i * TILESIZE, j * TILESIZE);
			if (data.map.tab[j][i] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
				data.wall.img.ptr_img, i * TILESIZE, j * TILESIZE);
			if (data.map.tab[j][i] == 'P')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
				data.perso.img.ptr_img, i * TILESIZE, j * TILESIZE);
			if (data.map.tab[j][i] == 'C')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
				data.collect.img.ptr_img, i * TILESIZE, j * TILESIZE);
			if (data.map.tab[j][i] == 'E')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
				data.exit.img.ptr_img, i * TILESIZE, j * TILESIZE);
		}
	}
}
