# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/26 16:18:40 by eduaserr          #+#    #+#              #
#    Updated: 2025/08/27 00:54:00 by eduaserr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Harl
CC		= g++
CFLAGS	= -Wall -Wextra -Werror -g -std=c++98

SRC		= main.cpp
SRCS	= src/Harl.cpp

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
	@$(RM) $(NAME)
	@echo "clearing executables"

re: fclean all

.PHONY: all clean fclean re