# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msenipek <tahasenipek@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 13:50:15 by msenipek          #+#    #+#              #
#    Updated: 2022/06/22 13:50:21 by msenipek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all		: server client

server	:
		$(CC) $(CFLAGS) server.c -o server

client	:
		$(CC) $(CFLAGS) client.c -o client

fclean	:
		rm -rf server client

re		: fclean all

.PHONY	: all fclean re server.o client.o
