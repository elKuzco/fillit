# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/17 13:53:06 by qlouisia          #+#    #+#              #
#    Updated: 2018/12/19 14:07:24 by qlouisia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fillit
LDFLAGS = -Llibft
LDLIBS = -lft
LIB_DIR = libft

SRC_NAME =	lst.c\
			entry.c\
			fillit.c\
			pieces_identification.c\
			print_tab.c\
			tab_function.c \
			main.c 

OBJ = $(SRC_NAME:.c=.o)

$(NAME): $(OBJ)
	cd $(LIB_DIR) && make
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@
	
all : $(NAME)

clean :
		/bin/rm -f $(OBJ)
		cd $(LIB_DIR) && make $@

fclean : clean
		/bin/rm -f $(NAME)
		/bin/rm -f libft/libft.a

re : fclean all
	cd $(LIB_DIR) && make