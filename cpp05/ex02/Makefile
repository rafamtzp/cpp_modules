NAME = main

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = AForm.cpp  Bureaucrat.cpp  main.cpp  \
	  PresidentialPardonForm.cpp  RobotomyRequestForm.cpp\
	  ShrubberyCreationForm.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(NAME)

fclean : clean
	rm -f $(OBJ)

re : fclean all

.PHONY: all clean fclean re
