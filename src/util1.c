/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:59:41 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/11 22:01:58 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_open_map(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error");
		exit(1);
	}
	return (fd);
}

void	ft_check_arg(int argc, char **argv, int fd)
{
	if (argc != 2)
		ft_printf("Error");
}
