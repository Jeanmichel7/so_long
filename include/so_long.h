/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:43:35 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/13 00:43:28 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 100
# define TILESIZE 48

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_img
{
	void	*ptr_img;
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

typedef struct s_map
{
	char	**tab;
	int		width;
	int		height;
}	t_map;

typedef struct s_font
{
	t_items	nul;
	t_items	one;
	t_items	two;
	t_items	three;
	t_items	four;
	t_items	five;
	t_items	six;
	t_items	seven;
	t_items	eight;
	t_items	nine;
}	t_font;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	t_items	wall;
	t_items	sky;
	t_items	perso;
	t_items	enemy;
	t_items	collect;
	t_items	exit;
	t_items	end;
	t_items	lumens;
	t_font	font;
	int		count_move;
	int		count_collect;
	int		count_collect_tot;
}	t_data;

int		ft_open_map(char **argv);
void	ft_check_arg(int argc, char **argv);
void	ft_stop_prog(char *msg, int error);
char	**ft_fill_map(int height, int width, t_list *list);
t_map	ft_get_map(int fd);
void	ft_check_map(t_data *data);
void	ft_init_items(t_data *data);

void	ft_create_img_map(t_data data);
void	ft_init_perso(t_data *data);

/*  EVENMENT KEYBOARD  */

int		deal_key(int key, t_data *data);
int		ft_is_move_allow(t_data *data, int key);
void	ft_exit_game(t_data *data);
void	ft_check_case(t_data *data);

/*  IMG  */
void	ft_init_perso(t_data *data);
//void	ft_init_perso_left(t_data *data);

/*  FONT  */
void	ft_init_font(t_data *data);
void	ft_display_count_move(t_data *data);
void	ft_display_lumens(t_data *data);

#endif