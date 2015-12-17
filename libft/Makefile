# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddela-cr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:43:54 by ddela-cr          #+#    #+#              #
#    Updated: 2015/12/11 16:54:01 by ddela-cr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc -I ../includes

FLAGS		=	-Wall -Wextra -Werror

SRC_C		=	ft_strlen.c\
ft_strcpy.c\
ft_strsplit.c\
ft_putstr.c\
ft_putchar.c

SRC_O		=	$(SRC_C:.c=.o)

.SILENT:

all:		$(NAME)

$(NAME): $(SRC_O)
	ar rc $(NAME) $(SRC_O)
	ranlib $(NAME)

clean:
	rm -f $(SRC_O)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		fclean clean re
