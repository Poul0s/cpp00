# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psalame <psalame@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 15:20:56 by psalame           #+#    #+#              #
#    Updated: 2023/12/11 15:59:02 by psalame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	megaphone.cpp

NAME	=	megaphone

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re