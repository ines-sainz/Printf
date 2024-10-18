# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 09:50:33 by isainz-r          #+#    #+#              #
#    Updated: 2024/02/29 09:32:23 by isainz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
AR      = ar
ARFLAGS = -rcs

SRCS = ft_putchar_fd.c ft_calloc.c ft_itoa.c ft_printf.c ft_divide_16.c \
	   ft_printf_organizer.c ft_long.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
