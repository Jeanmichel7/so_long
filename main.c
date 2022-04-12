/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:15:20 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/12 05:08:29 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	deal_key(int key, t_data *data)
{
	ft_printf("%d\n", key);
	if (key == 65307)
	{
		//mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	ft_check_arg(argc, argv);
	fd = ft_open_map(argv);
	data.map = ft_get_map(fd);
	ft_check_map(data.map);
	ft_init_items(&data);

	int i = 0;
	while (data.map.tab[i])
	{
		printf("line %d: '%s'\n", i, data.map.tab[i]);
		i++;
	}
	printf("pos user : %d %d\n", data.perso.pos_x, data.perso.pos_y);

	//data.img_ptr = mlx_png_file_to_image(data.mlx_ptr, enemy.file, &enemy.width, &enemy.height);
	//mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 150, 150);
	//mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 100, 100);

	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);
	if (close(fd))
		ft_stop_prog("Impossible de ferme le fichier map/***.ter", 1);
	return (0);
}
