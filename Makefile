# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agomez-b <gomezbarroso.a@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 00:00:59 by agomez-b          #+#    #+#              #
#    Updated: 2022/12/23 15:19:58 by agomez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a

SRC =	ft_printf.c
		
OBJS = $(SRC:.c=.o)

# INCLUDE = ft_printf.h

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

AR = ar rc
RM = rm -f


all :		$(LIBFT) $(NAME)

$(NAME):	$(OBJS)
			@cp $(LIBFT) $(NAME)
			@$(AR) $(NAME) $(OBJS)
			
$(LIBFT):
			@make -C ./libft

.c.o:
			@$(CC) -c $(CCFLAGS) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJS)
			@make clean -C ./libft
	
fclean:		clean
			@make fclean -C ./libft
			@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re libft