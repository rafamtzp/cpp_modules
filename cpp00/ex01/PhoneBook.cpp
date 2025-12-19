#include "PhoneBook.hpp"
#include <iomanip>


PhoneBook::PhoneBook(void)
{
	PhoneBook::index = 0;
	//std::cout << "Phonebook constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	//std::cout << "Phonebook destructor called" << std::endl;
	return ;
}

void PhoneBook::add_contact(void)
{
	std::cout << "Please enter their first name: ";
	getline(std::cin, this->contacts[this->index].firstname);
	std::cout << "Please enter their last name: ";
	getline(std::cin, this->contacts[this->index].lastname);
	std::cout << "Please enter their nickname: ";
	getline(std::cin, this->contacts[this->index].nickname);
	std::cout << "Please enter their phone number: ";
	getline(std::cin, this->contacts[this->index].number);
	std::cout << "Please enter their darkest secret (shh): ";
	getline(std::cin, this->contacts[this->index].secret);
	this->index++;
	if (this->index == 8)
		this->index = 0;
}

void PhoneBook::search_contact(void)
{
	std::string index = "0";

	std::cout
	<< std::string('-', 45) << std::endl
	<< std::right << "|" << std::setw(10) << "Index"
	<< std::right << "|" << std::setw(10) << "First Name"
	<< std::right << "|" << std::setw(10) << "Last Name"
	<< std::right << "|" << std::setw(10) << "Nickname"
	<< "|" << std::endl << std::string(45, '-') << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->contacts[i].has_data())
		{
			std::cout
			<< std::right << "|" << std::
		}
	}
	while (index == "0")
	{
		std::cout << "Please enter an index: ";
		std::getline(std::cin, index);
	}
	std::cout << "Index entered: " << index << std::endl;
	
}