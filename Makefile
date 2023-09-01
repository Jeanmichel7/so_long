# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 20:35:44 by jrasser           #+#    #+#              #
#    Updated: 2023/09/01 21:05:12 by jrasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC					= main.c \
						src/check_arg.c src/create_map.c src/check_map.c \
						src/init_items.c src/create_img_map.c \
						src/manage_keyboard.c src/allow_move.c \
						src/font.c src/init_items_bis.c \
						src/font_utils.c

OS					= ${shell uname}
OBJ					= ${SRC:.c=.o}
LIBFT				= $(MAKE) -C ./libft
LIBMLXMAC		= make -C mlx_mac/
LIBMLXLNUX	= make -C mlx_linux/
NAME				= so_long
CC					= gcc
RM					= rm -f
CFLAGS			= -Wall -Wextra -Werror
CPPFLAGS		= -I./include/ -I./libft/

ifeq ($(OS),Linux)
LDFLAGS			= -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz 
CPPFLAGS 		+= -Imlx_linux -I/usr/include -Imlx_linux
endif

ifeq ($(OS),Darwin)
LDFLAGS			= -Lmlx_mac -lmlx -framework OpenGL -framework AppKit -lm -lz
CPPFLAGS 		+= -Imlx_mac
endif

$(NAME):	$(OBJ)
				$(MAKE) -C ./libft
ifeq ($(OS),Darwin)
				$(LIBMLXMAC)
endif
				$(LIBMLXLNUX)
				$(CC) $(OBJ) -L./libft -lft $(LDFLAGS) -o $(NAME) -g

all:		${NAME}

bonus:	re

clean:
				${RM} ${OBJ}
	
fclean:	clean
				${RM} ${NAME}
				make fclean -C libft/
	
re:			fclean all

.PHONY:	all clean fclean re
