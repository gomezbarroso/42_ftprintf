# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agomez-b <agomez-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 00:00:59 by agomez-b          #+#    #+#              #
#    Updated: 2022/12/16 15:11:48 by agomez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c
		
OBJS = $(SRC:.c=.o)	

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBC = ar rcs

%.o: %.c
		$(CC) -c $(CFLAGS) $^


all : $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $@ $^

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean