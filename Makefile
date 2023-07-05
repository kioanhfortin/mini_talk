# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 19:00:47 by kfortin           #+#    #+#              #
#    Updated: 2022/11/16 18:13:13 by kfortin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

NAME_C = client
NAME_S = server

NAME_C_B = client_bonus
NAME_S_B = server_bonus

SRC_C = ./src/client.c src/ft_utilis_2.c src/ft_utilis_1.c
SRC_S = ./src/server.c src/ft_utilis_2.c src/ft_utilis_1.c
OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)

SRC_C_B = ./bonus_src/client_bonus.c bonus_src/ft_utilis_2_bonus.c bonus_src/ft_utilis_1_bonus.c
SRC_S_B = ./bonus_src/server_bonus.c bonus_src/ft_utilis_2_bonus.c bonus_src/ft_utilis_1_bonus.c
OBJ_C_B = $(SRC_C_B:.c=.o)
OBJ_S_B = $(SRC_S_B:.c=.o)

PRINTF = ./ft_printf/libftprintf.a
PRINTF_PATH = ./ft_printf/

				
all: client server

client: $(SRC_C) $(OBJ_C)
		make -C $(PRINTF_PATH)
		$(CC) $(CFLAGS) -o $(NAME_C) $(SRC_C) $(PRINTF)

server: $(SRC_S) $(OBJ_S) 
		$(CC) $(CFLAGS) -o $(NAME_S) $(SRC_S) $(PRINTF)
		
bonus: client_bonus server_bonus

client_bonus: $(SRC_C_B) $(OBJ_C_B)
		make -C $(PRINTF_PATH)
		$(CC) $(CFLAGS) -o $(NAME_C_B) $(SRC_C_B) $(PRINTF)

server_bonus: $(SRC_S_B) $(OBJ_S_B) 
		$(CC) $(CFLAGS) -o $(NAME_S_B) $(SRC_S_B) $(PRINTF)

clean:
		$(RM) $(OBJ_C) $(OBJ_S) $(OBJ_C_B) $(OBJ_S_B) 
		make -C $(PRINTF_PATH) clean

fclean: clean
		$(RM) $(NAME_C) $(NAME_S) $(NAME_C_B) $(NAME_S_B) $(PRINTF)

re: fclean all