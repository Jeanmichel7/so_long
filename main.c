/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:15:20 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/13 21:15:10 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	ft_check_arg(argc, argv);
	fd = ft_open_map(argv);
	data.map = ft_get_map(fd);
	ft_check_map(&data);
	ft_init_items(&data);
	ft_create_img_map(&data);
	ft_display_count_move(&data);
	ft_display_lumens(&data);
	ft_generate_enemy(&data);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_exit_game, &data);
	mlx_loop(data.mlx_ptr);
	if (close(fd))
		ft_stop_prog("Impossible de ferme le fichier map/***.ter", 1);
	free(data.map.tab);
	return (0);
}

void	ft_display_map(t_data *data)
{
	int i = 0;
	while (data->map.tab[i])
	{
		printf("line %d: '%s'\n", i, data->map.tab[i]);
		i++;
	}
}



