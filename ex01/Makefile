# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psalame <psalame@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 16:30:33 by psalame           #+#    #+#              #
#    Updated: 2023/12/13 15:30:37 by psalame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	src/main.cpp \
			src/get_input_not_empty.cpp \
			src/add_contact.cpp \
			src/search_contact.cpp \
			class/PhoneBook.cpp \

OBJ		=	$(addprefix obj/, $(SRC:.cpp=.o))

OBJ_DIR	=	$(sort $(dir $(OBJ)))

HEADER	=	-Iheader -Iclass

NAME	=	phonebook

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

obj/%.o: %.cpp
	$(CC) $(CFLAGS) $(HEADER) $^ -o $@ -c

$(OBJ_DIR):
	@mkdir -p $@

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re