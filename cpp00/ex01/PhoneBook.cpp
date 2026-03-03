#include "PhoneBook.hpp"
#include <iomanip>
#include <stdlib.h>


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
	if (this->contacts[index].has_data())
		this->index++;
	if (this->index == 8)
		this->index = 0;
}

static std::string truncate_entry(std::string str)
{
	std::string copy(str, 0, 10);

	if (str.length() > 10)
		copy[9] = '.';
	return (copy);
}

void PhoneBook::display_contact_info(std::string index)
{
	int i = atoi(index.c_str());

	if (this->contacts[i].has_data())
	{
		std::cout << "Contact Info:" << std::endl
		<< std::string(13, '-') << std::endl
		<< "First name: " << this->contacts[i].firstname << std::endl
		<< "Last name: " << this->contacts[i].lastname << std::endl
		<< "Nickname: " << this->contacts[i].nickname << std::endl
		<< "Phone number: " << this->contacts[i].number << std::endl
		<< "Secret (shh): " << this->contacts[i].number << std::endl;
	}
	return ;
}

void PhoneBook::display_table(void)
{
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
			<< std::right << "|" << std::setw(10) << (char)(i + 48)
			<< std::right << "|" << std::setw(10) << truncate_entry(this->contacts[i].firstname)
			<< std::right << "|" << std::setw(10) << truncate_entry(this->contacts[i].lastname)
			<< std::right << "|" << std::setw(10) << truncate_entry(this->contacts[i].nickname)
			<< "|" << std::endl << std::string(45, '-') << std::endl;
		}
	}
}

void PhoneBook::search_contact(void)
{
	std::string index = "\n";
	int i;

	display_table();
	while (index == "\n")
	{
		std::cout << "Please enter an index (or just press ENTER to quit): ";
		try
		{
			if (!std::getline(std::cin, index))
				return ;
			if (index.empty())
				break ;
			i = 0;
			while (i < (int)index.length() && index.at(i) == ' ')
			 	i++;
			if (i >= (int)index.length() || !isdigit(index.at(i)))
				throw std::invalid_argument("Invalid argument.");
			else if (atoi(index.c_str()) > 7)
				throw std::invalid_argument("Can only search indices 0-7.");
			else if (!this->contacts[atoi(index.c_str())].has_data())
				throw std::invalid_argument("Index not in list.");
		}
		catch (std::invalid_argument& err)
		{
			std::cout << err.what() << " Please try again." << std::endl;
			index = "\n";
		}
		if (index != "\n")
			display_contact_info(index);
	}
}
