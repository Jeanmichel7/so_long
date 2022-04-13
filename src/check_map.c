/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 03:42:32 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/13 23:14:59 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_border(t_map map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map.height)
	{
		i = 0;
		while (i < map.width)
		{
			if (map.tab[j][i] != '1' && ((j == 0 || j == map.height - 1)
				|| (i == 0 || i == map.width - 1)))
				ft_stop_prog("bordure ouverte", 0);
			i++;
		}
		j++;
	}
}

void	ft_check_nb_critere(int nb_start, int nb_exit, int nb_collect)
{
	if (nb_start == 0)
		ft_stop_prog("Pas de position de départ, bravo...", 0);
	if (nb_start > 1)
		ft_stop_prog("Trop de position de départ!", 0);
	if (nb_exit == 0)
		ft_stop_prog("Pas de position de sorti, non mais sérieux...", 0);
	if (nb_collect < 1)
		ft_stop_prog("nombre d'élement à collecter inférieur à 1, c'est \n \
		à dire 0... crétin, comment tu veux sortir de la carte si tu peux rien \n \
		récupérer. \n \
		Non mais réfléchi un peu c'est pas possible ca... \n \
		t'as toujours l'excuse du \"oups j'ai missclick\" mais bon on l'a \n \
		connait à force... REPREND TOI !!!", 0);
}

void	ft_check_critere(t_data *data)
{
	int	i;
	int	j;
	int	nb_start;
	int	nb_exit;

	nb_start = 0;
	nb_exit = 0;
	data->count_collect_tot = 0;
	j = -1;
	while (++j < data->map.height)
	{
		i = -1;
		while (++i < data->map.width)
		{
			if (data->map.tab[j][i] == 'C')
				data->count_collect_tot++;
			if (data->map.tab[j][i] == 'E')
				nb_exit ++;
			if (data->map.tab[j][i] == 'P')
				nb_start ++;
		}
	}
	ft_check_nb_critere(nb_start, nb_exit, data->count_collect_tot);
}

void	ft_check_map(t_data *data)
{
	ft_check_border(data->map);
	ft_check_critere(data);
}
