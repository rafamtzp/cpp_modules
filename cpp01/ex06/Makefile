NAME = harlFilter

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(NAME)

fclean : clean
	rm -f $(OBJ)

re : fclean all

.PHONY: all clean fclean re