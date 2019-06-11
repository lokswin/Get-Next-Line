#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drafe <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by drafe             #+#    #+#              #
#    Updated: 2019/06/07 21:10:23 by drafe            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = get_next_line.a

HEADERS = get_next_line.h

OBJ = get_next_line.o

SRC = get_next_line.c

all: $(NAME)

$(NAME):
	@$(CC) -c -I $(HEADERS) $(CFLAGS) $(SRC)
	@ar -rc $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
