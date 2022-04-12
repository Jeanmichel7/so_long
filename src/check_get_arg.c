/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_get_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:59:41 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/12 03:11:22 by jrasser          ###   ########.fr       */
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

char	**ft_fill_map(int height, int width, t_list *list)
{
	char	**map;

	map = malloc(sizeof(char*) * (height + 1));
	int i;
	i = 0;
	while (list)
	{
		map[i] = malloc(sizeof(char) * (width + i));
		map[i] = list->content;
		list = list->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**ft_get_map(int fd)
{
	char	*line;
	int		height;
	int		width;
	t_list	*list;

	height = 0;
	line = get_next_line(fd);
	width = ft_strlen(line);
	list = ft_lstnew(line);
	while (line)
	{
		if ((int)ft_strlen(line) != width)
			ft_stop_prog("longueur de map non identique", 0);
		if (height != 0)
			ft_lstadd_back(&list, ft_lstnew(line));
		line = get_next_line(fd);
		height++;
	}
	return (ft_fill_map(height, width, list));
}
