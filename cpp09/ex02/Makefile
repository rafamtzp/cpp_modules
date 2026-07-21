NAME = PmergeMe

CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean :
	rm -f $(NAME)

fclean : clean
	rm -f $(OBJ)

re : fclean all

.PHONY: all clean fclean re