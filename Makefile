# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 14:02:26 by ehakam            #+#    #+#              #
#    Updated: 2019/11/28 21:34:15 by ehakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*- #

NAME=libftprintf.a
MAKE=make
CC=gcc
CFLAGS=-Wall -Werror -Wextra
SRC=ft_printf.c \
	ft_data.c \
	ft_flags.c \
	ft_format.c \
	ft_itoa.c \
	ft_atoi.c \
	ft_itoh.c \
	ft_output.c \
	ft_spacing.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_find.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC) -c
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) *.a

re: fclean all

norm: fclean
	@norminette -R CheckForbiddenSourceHeader *.c *.h
