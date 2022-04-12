/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:16:51 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/13 00:57:55 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move_perso_up(t_data *data, int key)
{
	if(ft_is_move_allow(data, key))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->sky.img.ptr_img, data->perso.pos_x, data->perso.pos_y);
		data->perso.pos_y -= TILESIZE;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->perso.img.ptr_img, \
		data->perso.pos_x, data->perso.pos_y);
	}
	ft_check_case(data);
}

void	ft_move_perso_down(t_data *data, int key)
{
	if(ft_is_move_allow(data, key))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->sky.img.ptr_img, data->perso.pos_x, data->perso.pos_y);
		data->perso.pos_y += TILESIZE;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->perso.img.ptr_img, \
		data->perso.pos_x, data->perso.pos_y);
	}
	ft_check_case(data);
}

void	ft_move_perso_right(t_data *data, int key)
{
	if(ft_is_move_allow(data, key))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->sky.img.ptr_img, data->perso.pos_x, data->perso.pos_y);
		data->perso.pos_x += TILESIZE;
		data->perso.img.file = "img/rayman_right.png";
		data->perso.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->perso.img.file, \
		&data->perso.img.width, &data->perso.img.height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->perso.img.ptr_img, \
		data->perso.pos_x, data->perso.pos_y);
	}
	ft_check_case(data);
}

void	ft_move_perso_left(t_data *data, int key)
{
	if(ft_is_move_allow(data, key))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->sky.img.ptr_img, data->perso.pos_x, data->perso.pos_y);
		data->perso.pos_x -= TILESIZE;
		data->perso.img.file = "img/rayman_left.png";
		data->perso.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->perso.img.file, \
		&data->perso.img.width, &data->perso.img.height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->perso.img.ptr_img, \
		data->perso.pos_x, data->perso.pos_y);
	}
	ft_check_case(data);
}

int	deal_key(int key, t_data *data)
{
	if (key == 65307 || key == 53)
		ft_exit_game(data);
	if (key == 13)
		ft_move_perso_up(data, key);
	if (key == 1)
		ft_move_perso_down(data, key);
	if (key == 2)
		ft_move_perso_right(data, key);
	if (key == 0)
		ft_move_perso_left(data, key);
	ft_printf("%d/%d collectable	", data->count_collect, data->count_collect_tot);
	ft_printf("%d move\n", data->count_move);
	ft_display_count_move(data);
	//ft_display_lumens(data);
	return (0);
}
