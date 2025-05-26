# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 13:06:26 by matoledo          #+#    #+#              #
#    Updated: 2025/05/19 16:45:48 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftget_next_line.a

SRCS = ft_get_next_line.c \

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