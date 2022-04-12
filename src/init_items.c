/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 04:44:31 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/13 01:00:26 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_exit(t_data *data)
{
	data->exit.img.file = "img/exit48.png";
	data->exit.img.width = TILESIZE;
	data->exit.img.height = TILESIZE;
	data->exit.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->exit.img.file, \
	&data->exit.img.width, &data->exit.img.height);
}

void	ft_init_end(t_data *data)
{
	data->end.img.file = "img/end.png";
	data->end.img.width = TILESIZE;
	data->end.img.height = TILESIZE * 10;
	data->end.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->end.img.file, \
	&data->end.img.width, &data->end.img.height);
}

void	ft_init_lumens(t_data *data)
{
	data->lumens.img.file = "img/lumens.png";
	data->lumens.img.width = TILESIZE;
	data->lumens.img.height = 269;
	data->lumens.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->lumens.img.file, \
	&data->lumens.img.width, &data->lumens.img.height);
}

void	ft_init_items(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->count_move = 0;
	data->count_collect = 0;
	ft_init_dimension(data);
	ft_init_sky(data);
	ft_init_perso(data);
	ft_init_collect(data);
	ft_init_exit(data);
	ft_init_wall(data);
	ft_init_font(data);
	//ft_init_lumens(data);
	ft_init_end(data);
}
