# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2022/03/15 19:23:23 by supersko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = *.c

OBJS = ${SRCS:.c=.o}

NAME = get_next_line.a

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=42

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
	$(CC) $(SRCS) $(SRCS_BONUS) $(HEADER)
	./a.out
	rm a.out

debug:
	$(CC) -g $(SRCS) $(SRCS_BONUS) $(HEADER)
	lldb a.out
	rm a.out

.PHONY: all clean fclean re
