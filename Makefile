# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 20:35:44 by jrasser           #+#    #+#              #
#    Updated: 2022/04/09 21:49:25 by jrasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= main.c
				
OBJ				= ${SRC:.c=.o}
LIBFT			= make -C libft/
NAME			= so_long
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra
LDFLAGS			= -I./include/ -I./libft/

%.o: %.c
				$(CC) -Wall -Wextra -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): 		$(OBJ)
				${LIBFT}
				$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) libft/libft.a

all:			${NAME}
	
clean:			
				${RM} ${OBJ}
	
fclean:			clean
				${RM} ${NAME}
				make fclean -C libft/
	
re:				fclean all

.PHONY:			all clean fclean re
