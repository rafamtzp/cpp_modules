NAME = test

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = Account.cpp tests.cpp

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
