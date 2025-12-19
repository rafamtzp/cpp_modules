NAME = phonebook

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = Contact.cpp PhoneBook.cpp main.cpp
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re