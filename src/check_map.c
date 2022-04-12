/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 03:42:32 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/12 04:19:15 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    ft_check_border(t_map map)
{
	int i;
	int j;


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
		ft_stop_prog("nombre d'élement à collecter inférieur à 1, c'est \
		à dire 0... crétin \
		comment tu veux sortir de la carte si tu peux rien récupérer, \
		non mais réfléchi un peu c'est pas possible ca...\
		t'as toujours l'excuse du \"oups j'ai missclick\" mais bon on la \
		connait à forme... REPREND TOI !!!", 0);
}

void    ft_check_critere(t_map map)
{
	int i;
	int j;
	int nb_start;
	int nb_exit;
	int nb_collect;

	nb_start = 0;
	nb_exit = 0;
	nb_collect = 0;
	j = 0;
	while (j < map.height)
	{
		i = 0;
		while (i < map.width)
		{
			if (map.tab[j][i] == 'C')
				nb_collect ++;
			if (map.tab[j][i] == 'E')
				nb_exit ++;
			if (map.tab[j][i] == 'P')
				nb_start ++;
			i++;
		}
		j++;
	}
	ft_check_nb_critere(nb_start, nb_exit, nb_collect);
}

void	ft_check_map(t_map map)
{
	ft_check_border(map);
	ft_check_critere(map);
}