# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/26 16:18:40 by eduaserr          #+#    #+#              #
#    Updated: 2025/08/26 21:33:25 by eduaserr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= SedIs4Losers
CC		= g++
CFLAGS	= -Wall -Wextra -Werror -g -std=c++98

SRC		= main.cpp
SRCS	= src/createFile.cpp

### OBJS ###
OBJS	= $(SRC:.cpp=.o) $(SRCS:.cpp=.o)

### RULES ###
all : $(NAME)

$(NAME): $(OBJS)
	@echo "loading ..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "compiled successfully"

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "clearing...🧹"

fclean: clean
	@$(RM) $(NAME) *.txt filename.replace
	@echo "clearing executables"

re: fclean all

.PHONY: all clean fclean re