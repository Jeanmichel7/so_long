# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 20:35:44 by jrasser           #+#    #+#              #
#    Updated: 2022/04/12 03:11:20 by jrasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= main.c \
				src/check_get_arg.c
				
OS				= ${shell uname}
OBJ				= ${SRC:.c=.o}
LIBFT			= ./libft
LIBMLXMAC		= make -C mlx_mac/
NAME			= so_long
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra
CPPFLAGS		= -I./include/ -I./libft/

ifeq ($(OS),Linux)
LDFLAGS			= -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz 
CPPFLAGS 		+= -Imlx_linux -I/usr/include -Imlx_linux
endif

ifeq ($(OS),Darwin)
LDFLAGS			= -Lmlx_mac -lmlx -framework OpenGL -framework AppKit -lm -lz
CPPFLAGS 		+= -Imlx_mac
endif

$(NAME): 		$(OBJ) $(LIBFT)
ifeq ($(OS),Darwin)
				$(LIBMLXMAC)
endif
				$(MAKE) -C ./libft
				$(CC) $(OBJ) $(LDFLAGS) -o $(NAME) -L./libft -lft -g

all:			${NAME}
	
clean:			
				${RM} ${OBJ}
	
fclean:			clean
				${RM} ${NAME}
				make fclean -C libft/
	
re:				fclean all

.PHONY:			all clean fclean re
