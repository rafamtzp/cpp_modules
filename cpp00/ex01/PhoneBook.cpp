#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void)
{
	PhoneBook::index = 0;
	std::cout << "Phonebook constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Phonebook destructor called" << std::endl;
	return ;
}

void PhoneBook::add_contact(Contact contacts[], int index)
{
	std::cout << "Please enter their first name: ";
	std::cin >> contacts[index].firstname;
	std::cout << "Please enter their last name: ";
	std::cin >> contacts[index].lastname;
	std::cout << "Please enter their nickname: ";
	std::cin >> contacts[index].nickname;
	std::cout << "Please enter their phone number: ";
	std::cin >> contacts[index].number;
	std::cout << "Please enter their darkest secret (shh): ";
	std::cin >> contacts[index].secret;
	this->index++;
	if (index == 8)
		this->index = 0;
}

void PhoneBook::search_contact(Contact contacts[])
{
	char *index = "0";

	std::cout << "* table *" << std::endl;
	while (atoi(index) == 0)
	{
		std::cout << "Please enter an index: ";
		std::cin >> index;
	}
	std::cout << "Index entered: " << index << std::endl;
	
}