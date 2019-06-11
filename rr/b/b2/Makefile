#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drafe <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 16:42:00 by drafe             #+#    #+#              #
#    Updated: 2019/02/17 20:23:07 by drafe            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = bsq

OBJ =  $(wildcard *.o)

SRC = $(wildcard *.c)

INCLUDES = $(wildcard ft_headers.h)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -I$(INCLUDES) $(SRC) -o $(NAME)
clean:
	@rm -f $(OBJ) ft_headers.h.gch
fclean: clean
	@rm $(NAME)

re: fclean all
