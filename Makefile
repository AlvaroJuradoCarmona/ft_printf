# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 12:07:59 by ajurado-          #+#    #+#              #
#    Updated: 2023/01/26 14:49:27 by ajurado-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MSRC	=	ft_printf.c	\
			ft_print_types.c \
			ft_print_hex.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strlen.c 
MOBJ	= $(MSRC:.c=.o)
NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MOBJ)
		ar -rc $(NAME) $(MOBJ)

clean:
		$(RM) $(MOBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
