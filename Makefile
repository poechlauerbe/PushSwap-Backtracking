# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 08:52:53 by bpochlau          #+#    #+#              #
#    Updated: 2023/11/20 15:40:13 by bpochlau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -O0 -g
HEADER = push_swap.h
LIB = libft/libft.a
SRCS = \
	push_swap.c \
	exit.c \
	fun_base.c \
	fun_rev_rot.c \
	fun_rot.c \
	fun_sp.c \
	input.c \
	list_utils.c \
	sort_4.c \
	sort_fun.c \
	turk.c \
	utils.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(HEADER) $(OBJS)
	$(MAKE) -C libft
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME) $(LIB)

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

.phony: all clean fclean re
