# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstarov <dstarov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/25 19:24:24 by dstarov           #+#    #+#              #
#    Updated: 2023/07/02 15:30:18 by dstarov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a

HEADER = src/ft_printf.h

SRCS = libft/ft_putchar_fd.c \
	libft/ft_itoa.c \
	libft/ft_putstr_fd.c \
	libft/ft_strlen.c \
	src/ft_printf.c \
	src/ft_print_char.c \
	src/ft_print_dec.c \
	src/ft_print_str.c \
	src/ft_print_hex.c \
	src/ft_print_unsign.c \
	src/ft_print_ptr.c

CFLAGS	= -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

.c.o:
	cc $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	ar rcs $(NAME) $(SRCS) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re