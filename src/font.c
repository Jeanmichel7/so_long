/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 23:44:02 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/13 23:51:34 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_display_count_move(t_data *data)
{
	char	*str_count;
	int		i;

	str_count = ft_itoa(data->count_move);
	i = 0;
	while (str_count[i])
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->wall.img.ptr_img, i * TILESIZE, 0);
		ft_display_count_move_0_4(data, str_count[i], i * TILESIZE, 0);
		ft_display_count_move_5_9(data, str_count[i], i * TILESIZE, 0);
		i++;
	}
}

void	ft_display_lumens_count(t_data *data, int *i, char *str_count)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->wall.img.ptr_img, *i * TILESIZE, TILESIZE * (data->map.height - 1));
	ft_display_count_move_0_4(data, str_count[*i], *i * TILESIZE, \
	TILESIZE * (data->map.height - 1));
	ft_display_count_move_5_9(data, str_count[*i], *i * TILESIZE, \
	TILESIZE * (data->map.height - 1));
	*i += 1;
}

void	ft_display_lumens_count_tot(t_data *data, int *i, int *j, char *str_tot)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->wall.img.ptr_img, *i * TILESIZE, TILESIZE * (data->map.height - 1));
	ft_display_count_move_0_4(data, str_tot[*j], *i * TILESIZE, \
	TILESIZE * (data->map.height - 1));
	ft_display_count_move_5_9(data, str_tot[*j], *i * TILESIZE, \
	TILESIZE * (data->map.height - 1));
	*i += 1;
	*j += 1;
}

void	ft_display_lumens(t_data *data)
{
	char	*str_count;
	char	*str_count_tot;
	int		i;
	int		j;

	str_count = ft_itoa(data->count_collect);
	str_count_tot = ft_itoa(data->count_collect_tot);
	i = 0;
	while (str_count[i])
		ft_display_lumens_count(data, &i, str_count);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->wall.img.ptr_img, i * TILESIZE, TILESIZE * (data->map.height - 1));
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->font.slash.img.ptr_img, i * TILESIZE, \
	TILESIZE * (data->map.height - 1));
	i++;
	j = 0;
	while (str_count_tot[j])
		ft_display_lumens_count_tot(data, &i, &j, str_count_tot);
}

void	ft_init_font(t_data *data)
{
	data->font.lose.img.file = "img/perdu.png";
	data->font.lose.img.width = TILESIZE;
	data->font.lose.img.height = TILESIZE;
	data->font.lose.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, \
	data->font.lose.img.file, &data->font.lose.img.width, \
	&data->font.lose.img.height);
	data->font.slash.img.file = "img/slash.png";
	data->font.slash.img.width = TILESIZE;
	data->font.slash.img.height = TILESIZE;
	data->font.slash.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, \
	data->font.slash.img.file, &data->font.slash.img.width, \
	&data->font.slash.img.height);
	ft_init_font_0_3(data);
	ft_init_font_4_7(data);
	ft_init_font_8_9(data);
}
