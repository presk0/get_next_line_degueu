# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2022/03/22 14:42:19 by supersko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line.c ft_list.c

OBJS = ${SRCS:.c=.o}

NAME = get_next_line.a

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=4

HEADER = get_next_line.h

CC = gcc

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS) $(HEADER)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	$(CC) $(SRCS) $(HEADER)
	./a.out

debug:
	$(CC) -g $(SRCS) $(HEADER)
	lldb a.out

.PHONY: all clean fclean re
