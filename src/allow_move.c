/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allow_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:47:26 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/13 23:23:46 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_is_move_allow(t_data *data, int key)
{
	int	allow;
	int	pos_x;
	int	pos_y;

	allow = 1;
	pos_x = data->perso.pos_x / TILESIZE;
	pos_y = data->perso.pos_y / TILESIZE;
	if (key == 2 && (data->map.tab[pos_y][pos_x + 1] == '1'
		|| (data->map.tab[pos_y][pos_x + 1] == 'E'
		&& data->count_collect != data->count_collect_tot)))
		return (0);
	if (key == 13 && (data->map.tab[pos_y - 1][pos_x] == '1'
		|| (data->map.tab[pos_y - 1][pos_x] == 'E'
		&& data->count_collect != data->count_collect_tot)))
		return (0);
	if (key == 0 && (data->map.tab[pos_y][pos_x - 1] == '1'
		|| (data->map.tab[pos_y][pos_x - 1] == 'E'
		&& data->count_collect != data->count_collect_tot)))
		return (0);
	if (key == 1 && (data->map.tab[pos_y + 1][pos_x] == '1'
		|| (data->map.tab[pos_y + 1][pos_x] == 'E'
		&& data->count_collect != data->count_collect_tot)))
		return (0);
	data->count_move++;
	return (allow);
}

void	ft_update_door(t_data *data)
{
	data->exit.img.file = "img/door_close.png";
	data->exit.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, \
	data->exit.img.file, &data->exit.img.width, &data->exit.img.height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->exit.img.ptr_img, data->exit.pos_x, data->exit.pos_y);
}

void	ft_display_lose(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->font.lose.img.ptr_img, data->map.width * TILESIZE / 2 - 102, \
	data->map.height * TILESIZE / 2 - 24);
	data->is_end = 1;
}

void	ft_check_case(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->perso.pos_x / TILESIZE;
	pos_y = data->perso.pos_y / TILESIZE;
	if (data->map.tab[pos_y][pos_x] == 'C')
	{
		data->count_collect++;
		data->map.tab[pos_y][pos_x] = '0';
	}
	if (data->map.tab[pos_y][pos_x] == 'X')
		ft_display_lose(data);
	if (data->count_collect == data->count_collect_tot)
		ft_update_door(data);
	if (data->map.tab[pos_y][pos_x] == 'E'
		&& data->count_collect == data->count_collect_tot)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->end.img.ptr_img, data->map.width * TILESIZE / 2 - 235, \
		data->map.height * TILESIZE / 2 - 24);
		data->is_end = 1;
	}
}
