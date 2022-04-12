/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 04:44:31 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/12 05:08:38 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    ft_init_dimension(t_data *data)
{
    int width_pixel;
    int height_pixel;

    width_pixel = 32 * (data->map.width);
    height_pixel = 32 * (data->map.height);
    data->win_ptr = mlx_new_window(data->mlx_ptr, width_pixel, height_pixel, "My game");
}

void    ft_init_perso(t_data *data)
{
    int x;
    int y;

    y = 0;
    while (data->map.tab[y][x] != 'P' && y < data->map.height - 1)
    {
        x = 0;
        while (data->map.tab[y][x] != 'P' && x < data->map.width - 1)
            x++;
        y++;
    }
    data->perso.name = "user";
    data->perso.pos_x = x;
    data->perso.pos_y = y - 1;
}

void	ft_init_items(t_data *data)
{
	data->mlx_ptr = mlx_init();
    ft_init_dimension(data);
	ft_init_perso(data);
    //ft_init_enemy(data);

	data->enemy.img.file = "img/enemy1.png";
	data->enemy.img.width = 50;
	data->enemy.img.height = 50;
}
