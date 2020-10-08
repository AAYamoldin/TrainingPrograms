# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjennine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 14:47:41 by mjennine          #+#    #+#              #
#    Updated: 2020/09/28 16:04:09 by mjennine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GCC_FILES = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c \
		srcs/ft_strlen.c srcs/ft_swap.c

RANLIB_FILES = ft_putchar.o ft_putstr.o ft_strcmp.o \
			   ft_strlen.o ft_swap.o

INCLUDES = includes/

all: $(NAME)
$(NAME):
	gcc -Wall -Wextra -Werror -c $(GCC_FILES) -I $(INCLUDES)
	ar rc $(NAME) $(RANLIB_FILES)
	ranlib $(NAME)

clean: 
	/bin/rm -f $(RANLIB_FILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

