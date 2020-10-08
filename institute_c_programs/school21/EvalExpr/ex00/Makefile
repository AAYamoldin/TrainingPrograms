# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjennine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/03 16:02:38 by mjennine          #+#    #+#              #
#    Updated: 2020/10/04 22:27:24 by mjennine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr

FILES = main.c additional_f.c additional_f2.c additional_f3.c eval_expr.c

all:
	gcc -Wall -Wextra -Werror $(FILES) -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

