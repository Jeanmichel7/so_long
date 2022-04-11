# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 20:35:44 by jrasser           #+#    #+#              #
#    Updated: 2022/04/11 18:57:02 by jrasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= main.c
				
OS				= ${shell uname}
OBJ				= ${SRC:.c=.o}
LIBFT			= ./libft
LIBMLXMAC		= make -C mlx_mac/
NAME			= so_long
CC				= gcc
RM				= rm -f
LDFLAGS			= -L./libft -lft
CFLAGS			= -Wall -Wextra
CPPFLAGS		= -I./include/ -I./libft/

ifeq ($(OS),Linux)
LDFLAGS			+= -Lmlx_linux -lmlx_Linux -L/usr/lib  -lXext -lX11 -lm -lz
CPPFLAGS 		+= -Imlx_linux -I/usr/include -Imlx_linux
endif

ifeq ($(OS),Darwin)
LDFLAGS			+= -Lmlx_mac -lmlx -framework OpenGL -framework AppKit -lm -lz
CPPFLAGS 		+= -Imlx_mac
endif

$(NAME): 		$(OBJ) $(LIBFT)
ifeq ($(OS),Darwin)
				$(LIBMLXMAC)
endif
				$(MAKE) -C ./libft
				$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)

all:			${NAME}
	
clean:			
				${RM} ${OBJ}
	
fclean:			clean
				${RM} ${NAME}
				make fclean -C libft/
	
re:				fclean all

.PHONY:			all clean fclean re
