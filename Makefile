# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 21:52:28 by eeravci           #+#    #+#              #
#    Updated: 2025/03/26 13:35:09 by eeravci          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

# Directories
FT_PRINTF_DIR = ft_printf

# Source files for server
SRCS_SERVER = server.c $(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/ft_printhex.c \
              $(FT_PRINTF_DIR)/ft_printnumber.c $(FT_PRINTF_DIR)/ft_printpercent.c \
              $(FT_PRINTF_DIR)/ft_printptr.c $(FT_PRINTF_DIR)/ft_printstring.c \
              $(FT_PRINTF_DIR)/ft_printunsigned.c

# Source files for client
SRCS_CLIENT = client.c $(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/ft_printhex.c \
              $(FT_PRINTF_DIR)/ft_printnumber.c $(FT_PRINTF_DIR)/ft_printpercent.c \
              $(FT_PRINTF_DIR)/ft_printptr.c $(FT_PRINTF_DIR)/ft_printstring.c \
              $(FT_PRINTF_DIR)/ft_printunsigned.c

# Object files
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Build targets
all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

# Cleanup
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all
