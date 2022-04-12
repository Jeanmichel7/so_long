/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:59:41 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/12 03:42:41 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_stop_prog(char *msg, int error)
{
	ft_printf("Error: %s\n", msg);
	exit(error);
}

int	ft_open_map(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_stop_prog("Impossible d'ouvrir la map", 1);
	return (fd);
}

void	ft_check_arg(int argc, char **argv)
{
	char	*ext;

	if (argc != 2)
		ft_stop_prog("Nombre d'arguments invalide", 0);
	ext = ft_split(argv[1], '.')[1];
	if (ft_strncmp(ext, "ber", 3) || ft_strlen(ext) != 3)
		ft_stop_prog("Extension de la carte invalide", 0);
}
