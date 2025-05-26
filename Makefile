# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 19:53:00 by matoledo          #+#    #+#              #
#    Updated: 2025/05/26 19:59:41 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
		push_swap_utils.c \

OBJS = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft all
	@$(CC) -o $(NAME) $(OBJS) -L./libft -l:libft.a

%.o: %.c
	@$(CC) -c $(CFLAGS) $<

clean:
	$(MAKE) -C ./libft clean
	@rm -rf *.o

fclean: clean
	$(MAKE) -C ./libft fclean
	@rm -rf $(NAME)

re: fclean all
	$(MAKE) -C ./libft re