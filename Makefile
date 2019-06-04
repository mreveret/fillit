# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: machoffa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/27 14:18:33 by machoffa          #+#    #+#              #
#    Updated: 2019/05/30 17:41:58 by mreveret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror -I.

DIR = includes

PATH_SRC = ./srcs/

SRCS = $(PATH_SRC)check_tetri.c \
	  $(PATH_SRC)fillit.c \
	  $(PATH_SRC)main.c \
	  $(PATH_SRC)setup_backtracking.c \
	  $(PATH_SRC)tabopti.c \
	  $(PATH_SRC)free.c

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft/

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	gcc $(CFLAGS) $(SRCS) -L./libft -lft -o $(NAME)

%.o: %.c
	gcc -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJS)
	rm -f libft/*.o
	rm -f libft/libft.a

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
