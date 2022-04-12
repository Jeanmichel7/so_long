/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allow_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:47:26 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/12 22:58:03 by jrasser          ###   ########.fr       */
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

	//ft_printf("posX : %d, posY : %d, '%c'\n", posX, posY, data->map.tab[posY][posX]);
	if (data->map.tab[posY][posX] == 'C')
	{
		data->count_collect++;
		data->map.tab[posY][posX] = '0';
	}
	//if (data->count_collect == data->count_collect_tot)
	//{
	//	printf("FELICITATION\n");
	//}
	if (data->map.tab[posY][posX] == 'E')
	{
		ft_printf("Feliciation tu as gagnem t'es vraient trop fort toi dis donc\n\n");
	}
}
