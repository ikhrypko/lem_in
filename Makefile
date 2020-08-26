# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 21:30:48 by ikhrypko          #+#    #+#              #
#    Updated: 2018/11/06 21:58:20 by ikhrypko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft/
LIBNAME = $(LIB)libft.a
HEADERS = lem-in.h
FILES = main.c writ.c tools.c tools2.c move.c valid.c bfs.c show.c options.c
OBJS = $(FILES:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS)
	@make -C $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBNAME) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJS)
	@make -C $(LIB) clean

fclean: clean
	@make -C $(LIB) fclean
	@rm -rf $(NAME)

re: fclean all

