# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 13:02:55 by matoledo          #+#    #+#              #
#    Updated: 2025/05/19 16:46:37 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRCS = ft_printf.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C .. all
	ar -rcs $(NAME) $(OBJS) ../*.o

%.o: %.c
	$(CC) -c $(CFLAGS) $<

#PHONY is used when a target is not gonna create a file
#this way if smoehow anyfile is called like the target there are no problems
.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	$(MAKE) -C .. clean
	rm -rf *.o

.PHONY: fclean
fclean:
	$(MAKE) -C .. fclean
	rm -rf *.o *.a

.PHONY: re
re: fclean all