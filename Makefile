# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 21:52:28 by eeravci           #+#    #+#              #
#    Updated: 2025/03/16 15:15:41 by eeravci          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = client.c server.c

OBJS = $(SRCS:.c=.o)

CC = clang
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME_SERVER = server
NAME_CLIENT = client

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): server.o
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_CLIENT): client.o
	$(CC) $(CFLAGS) -o $@ $^

server.o: server.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

client.o: client.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f server.o client.o

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
