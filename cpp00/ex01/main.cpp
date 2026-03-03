#include <iostream>
#include "PhoneBook.hpp"

std::string	uppercase(std::string s)
{
	for (int i = 0; i < s.length(); i++)
		s[i] = std::toupper(s[i]);
	return s;
}

int main(void)
{
	std::string action;
	PhoneBook phonebook;

	while (1)
	{
		std::cout << std::string(50, '-') << std::endl;
		std::cout << "Welcome to your phone book!" << std::endl;
		std::cout << "> Please type an action (ADD, SEARCH, or EXIT): ";
		if (!std::getline(std::cin, action))
			return (1);
		if (uppercase(action) == "ADD")
			phonebook.add_contact();
		else if (uppercase(action) == "SEARCH")
			phonebook.search_contact();
		else if (uppercase(action) == "EXIT")
			break ;
	}
}
