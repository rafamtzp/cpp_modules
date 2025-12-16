#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void)
{
	std::cout << "Phonebook constructor called" << std::endl;
	PhoneBook::contacts = Contact::Contact[8];
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Phonebook destructor called" << std::endl;
	return ;
}