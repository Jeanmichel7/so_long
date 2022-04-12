/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:43:35 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/12 03:52:33 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 100

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_img
{
	char	*file;
	int		width;
	int		height;
}	t_img;

typedef struct s_items
{
	char	*name;
	int		pos_x;
	int		pos_y;
	t_img	img;
}	t_items;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_items	perso;
	t_items	wall;
	t_items	enemy;
}	t_data;

typedef struct s_map
{
	char	**tab;
	int		width;
	int		height;
}	t_map;

int		ft_open_map(char **argv);
void	ft_check_arg(int argc, char **argv);
void	ft_stop_prog(char *msg, int error);
char	**ft_fill_map(int height, int width, t_list *list);
t_map	ft_get_map(int fd);
void	ft_check_map(t_map map);

#endif