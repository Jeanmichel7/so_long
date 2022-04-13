/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:37:57 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/13 22:01:42 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_font_0_4(t_data *data)
{
	data->font.nul.img.file = "img/font/nul.png";
	data->font.nul.img.width = TILESIZE;
	data->font.nul.img.height = TILESIZE;
	data->font.nul.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->font.nul.img.file, \
	&data->font.nul.img.width, &data->font.nul.img.height);
	data->font.one.img.file = "img/font/one.png";
	data->font.one.img.width = TILESIZE;
	data->font.one.img.height = TILESIZE;
	data->font.one.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->font.one.img.file, \
	&data->font.one.img.width, &data->font.one.img.height);
	data->font.two.img.file = "img/font/two.png";
	data->font.two.img.width = TILESIZE;
	data->font.two.img.height = TILESIZE;
	data->font.two.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->font.two.img.file, \
	&data->font.two.img.width, &data->font.two.img.height);
	data->font.three.img.file = "img/font/three.png";
	data->font.three.img.width = TILESIZE;
	data->font.three.img.height = TILESIZE;
	data->font.three.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->font.three.img.file, \
	&data->font.three.img.width, &data->font.three.img.height);
	data->font.four.img.file = "img/font/four.png";
	data->font.four.img.width = TILESIZE;
	data->font.four.img.height = TILESIZE;
	data->font.four.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->font.four.img.file, \
	&data->font.four.img.width, &data->font.four.img.height);
}

void	ft_init_font_5_9(t_data *data)
{
	data->font.five.img.file = "img/font/five.png";
	data->font.five.img.width = TILESIZE;
	data->font.five.img.height = TILESIZE;
	data->font.five.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->font.five.img.file, \
	&data->font.five.img.width, &data->font.five.img.height);
	data->font.six.img.file = "img/font/six.png";
	data->font.six.img.width = TILESIZE;
	data->font.six.img.height = TILESIZE;
	data->font.six.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->font.six.img.file, \
	&data->font.six.img.width, &data->font.six.img.height);
	data->font.seven.img.file = "img/font/seven.png";
	data->font.seven.img.width = TILESIZE;
	data->font.seven.img.height = TILESIZE;
	data->font.seven.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->font.seven.img.file, \
	&data->font.seven.img.width, &data->font.seven.img.height);
	data->font.eight.img.file = "img/font/eight.png";
	data->font.eight.img.width = TILESIZE;
	data->font.eight.img.height = TILESIZE;
	data->font.eight.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->font.eight.img.file, \
	&data->font.eight.img.width, &data->font.eight.img.height);
	data->font.nine.img.file = "img/font/nine.png";
	data->font.nine.img.width = TILESIZE;
	data->font.nine.img.height = TILESIZE;
	data->font.nine.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->font.nine.img.file, \
	&data->font.nine.img.width, &data->font.nine.img.height);
}

void	ft_init_font(t_data *data)
{
	data->font.lose.img.file = "img/perdu.png";
	data->font.lose.img.width = TILESIZE;
	data->font.lose.img.height = TILESIZE;
	data->font.lose.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->font.lose.img.file, \
	&data->font.lose.img.width, &data->font.lose.img.height);
	data->font.slash.img.file = "img/slash.png";
	data->font.slash.img.width = TILESIZE;
	data->font.slash.img.height = TILESIZE;
	data->font.slash.img.ptr_img = mlx_png_file_to_image(data->mlx_ptr, data->font.slash.img.file, \
	&data->font.slash.img.width, &data->font.slash.img.height);
	ft_init_font_0_4(data);
	ft_init_font_5_9(data);
}

void	ft_display_count_move_0_4(t_data *data, char c, int pos_x, int pos_y)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->font.nul.img.ptr_img, pos_x, pos_y);
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->font.one.img.ptr_img, pos_x, pos_y);
	if (c == '2')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->font.two.img.ptr_img, pos_x, pos_y);
	if (c == '3')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->font.three.img.ptr_img, pos_x, pos_y);
	if (c == '4')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->font.four.img.ptr_img, pos_x, pos_y);
}

void	ft_display_count_move_5_9(t_data *data,char c, int pos_x, int pos_y)
{
	if (c == '5')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->font.five.img.ptr_img, pos_x, pos_y);
	if (c == '6')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->font.six.img.ptr_img, pos_x, pos_y);
	if (c == '7')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->font.seven.img.ptr_img, pos_x, pos_y);
	if (c == '8')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->font.eight.img.ptr_img, pos_x, pos_y);
	if (c == '9')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->font.nine.img.ptr_img, pos_x, pos_y);
}

void	ft_display_count_move(t_data *data)
{
	char	*str_count;
	int		i;

	str_count = ft_itoa(data->count_move);
	i = 0;
	while (str_count[i])
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->wall.img.ptr_img, i * TILESIZE, 0);
		ft_display_count_move_0_4(data, str_count[i], i * TILESIZE, 0);
		ft_display_count_move_5_9(data, str_count[i], i * TILESIZE, 0);
		i++;
	}
}

void	ft_display_lumens(t_data *data)
{
	char	*str_count;
	char	*str_count_tot;
	int		i;

	str_count = ft_itoa(data->count_collect);
	str_count_tot = ft_itoa(data->count_collect_tot);
	ft_printf("%s %d\n", str_count_tot, data->count_collect_tot);
	i = 0;
	while (str_count[i])
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->wall.img.ptr_img, i * TILESIZE, TILESIZE * (data->map.height - 1));
		ft_display_count_move_0_4(data, str_count[i], i * TILESIZE, TILESIZE * (data->map.height - 1));
		ft_display_count_move_5_9(data, str_count[i], i * TILESIZE, TILESIZE * (data->map.height - 1));
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->font.slash.img.ptr_img, i * TILESIZE, TILESIZE * (data->map.height - 1));
	i = 0;
	while (str_count_tot[i])
	{
		ft_display_count_move_0_4(data, str_count_tot[i], i * (TILESIZE) + 2 * TILESIZE, TILESIZE * (data->map.height - 1));
		ft_display_count_move_5_9(data, str_count_tot[i], i * (TILESIZE) + 2 * TILESIZE, TILESIZE * (data->map.height - 1));
		i++;
	}
}
