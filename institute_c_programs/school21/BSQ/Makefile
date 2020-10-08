# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgerard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 12:44:53 by sgerard           #+#    #+#              #
#    Updated: 2020/10/07 20:47:38 by sgerard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE	= bsq
PRG = ./srcs/bsq.c
SRC = ./srcs/ft_fun.c ./srcs/ft_keys.c ./srcs/ft_map1.c ./srcs/ft_valid.c ./srcs/ft_mapcalc.c
KEY = -Wall -Wextra -Werror

all:
	gcc $(KEY) $(PRG) $(SRC) -o $(EXE)

clean: fclean
	rm -f $(EXE)

fclean:
	rm -f *.o

re: clean all
