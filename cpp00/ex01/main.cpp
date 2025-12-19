#include <iostream>
#include "PhoneBook.hpp"


int main(void)
{
	std::string action;
	PhoneBook phonebook;

	while (1)
	{
		std::cout << "Welcome to your phone book!" << std::endl;
		std::cout << "Plase type an action (ADD, SEARCH, or EXIT): ";
		std::getline(std::cin, action);
		if (action == "ADD")
			phonebook.add_contact();
		else if (action == "SEARCH")
			phonebook.search_contact();
		else if (action == "EXIT")
			break ;
	}
}
