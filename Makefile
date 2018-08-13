# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 16:20:34 by oshvorak          #+#    #+#              #
#    Updated: 2018/08/01 17:26:03 by oshvorak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++11

SRC = 	./src/main.cpp \
	./src/VM.cpp \
	./src/OperandFactory.cpp \
	./src/Parser.cpp

OBJS =	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

.cpp.o:
	@$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
