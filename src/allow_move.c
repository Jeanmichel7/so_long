/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allow_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:47:26 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/13 21:03:20 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_is_move_allow(t_data *data, int key)
{
	int	allow;
	int	posX;
	int	posY;

	allow = 1;
	posX = data->perso.pos_x / TILESIZE;
	posY = data->perso.pos_y / TILESIZE;	
	if (key == 2 && (data->map.tab[posY][posX + 1] == '1'
		|| (data->map.tab[posY][posX + 1] == 'E'
		&& data->count_collect != data->count_collect_tot)))
		return (0);
	if (key == 13 && (data->map.tab[posY - 1][posX] == '1'
		|| (data->map.tab[posY - 1][posX] == 'E'
		&& data->count_collect != data->count_collect_tot)))
		return (0);
	if (key == 0 && (data->map.tab[posY][posX - 1] == '1'
		|| (data->map.tab[posY][posX - 1] == 'E'
		&& data->count_collect != data->count_collect_tot)))
		return (0);
	if (key == 1 && (data->map.tab[posY + 1][posX] == '1'
		|| (data->map.tab[posY + 1][posX] == 'E'
		&& data->count_collect != data->count_collect_tot)))
		return (0);
	data->count_move++;
	return (allow);
}

void	ft_check_case(t_data *data)
{
	int	posX;
	int	posY;

	posX = data->perso.pos_x / TILESIZE;
	posY = data->perso.pos_y / TILESIZE;
	if (data->map.tab[posY][posX] == 'C')
	{
		data->count_collect++;
		data->map.tab[posY][posX] = '0';
	}
	if (data->map.tab[posY][posX] == 'X')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->font.lose.img.ptr_img, \
		data->map.width * TILESIZE / 2 - 102, data->map.height * TILESIZE / 2 - 24);
		data->is_end = 1;
	}
	if (data->count_collect == data->count_collect_tot)
	{
		data->exit.img.file = "img/door_close.png";
		data->exit.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->exit.img.file, \
		&data->exit.img.width, &data->exit.img.height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit.img.ptr_img, \
		data->exit.pos_x, data->exit.pos_y);
	}
	if (data->map.tab[posY][posX] == 'E' && data->count_collect == data->count_collect_tot)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->end.img.ptr_img, data->map.width * TILESIZE / 2 - 235, data->map.height * TILESIZE / 2 - 24);
		data->is_end = 1;
	}
}
