/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:15:20 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/12 04:00:41 by jrasser          ###   ########.fr       */
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

void	ft_init_items(t_data *data, char **map)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, (32 * ft_strlen(map[0])), 500, "My game");

	data->enemy.img.file = "img/enemy1.png";
	data->enemy.img.width = 50;
	data->enemy.img.height = 50;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;
	t_map	map;

	ft_check_arg(argc, argv);
	fd = ft_open_map(argv);
	map = ft_get_map(fd);
	//printf("map : %d %d\n", map.width, map.height);
	ft_check_map(map);


	
	ft_init_items(&data, map.tab);

	int i = 0;
	while (map.tab[i])
	{
		printf("line %d: '%s'\n", i, map.tab[i]);
		i++;
	}


	//data.img_ptr = mlx_png_file_to_image(data.mlx_ptr, enemy.file, &enemy.width, &enemy.height);
	//mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 150, 150);
	//mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 100, 100);

	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);
	if (close(fd))
		ft_stop_prog("Impossible de ferme le fichier map/***.ter", 1);
	return (0);
}
