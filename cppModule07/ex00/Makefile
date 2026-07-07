NAME    = whatever
CC      = g++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC     = main.cpp

OBJS    = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "loading ..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "compiled successfully"

%.o: %.cpp Whatever.hpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "clearing...🧹"

fclean: clean
	@$(RM) $(NAME)
	@echo "clearing executables"

re: fclean all

.PHONY: all clean fclean re