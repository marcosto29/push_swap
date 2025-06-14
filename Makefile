# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 19:53:00 by matoledo          #+#    #+#              #
#    Updated: 2025/06/12 12:17:25 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

#
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
		search_utils.c \
		push_swap_utils.c \
		sort_algorithm.c \
		input_parse.c \
		del_management.c \
		3_elements.c \
		checker.c \

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft all
	@$(CC) -o $(NAME) $(OBJS) -L./libft -l:libft.a

%.o: %.c
	@$(CC) -c $(CFLAGS) $<

clean:
	@$(MAKE) -C ./libft clean
	@rm -rf *.o

fclean: clean
	@$(MAKE) -C ./libft fclean
	@rm -rf $(NAME)

re: fclean all
	@$(MAKE) -C ./libft re