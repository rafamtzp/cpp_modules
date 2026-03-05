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
	int is_valid = 1;
	std::string input;
	std::string fields[5] {
		"firstname",
		"lastname",
		"nickname",
		"number",
		"secret"
	};

	for (int i = 0; i < 5 && is_valid == 1; i++)
	{
		std::cout << "Please enter their "<<fields[i]<<": ";
		getline(std::cin, input);
		if (fields[i] != "number")
			is_valid = contacts[index].setField(fields[i], input);
		else
			is_valid = contacts[index].setNumber(input);
		std::cout << is_valid<<std::endl;
	}
	if (is_valid == 1)
		this->index++;
	else if (is_valid == 0)
		std::cout << "(!!)Invalid entry (non-ascii or empty).\nPlease try again"<<std::endl;
	else if (is_valid == -1)
		std::cout << "(!!) Invalid number (only digits, spaces, + and -)"<<std::endl;
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
		<< "First name: " << this->contacts[i].getField("firstname") << std::endl
		<< "Last name: " << this->contacts[i].getField("lastname") << std::endl
		<< "Nickname: " << this->contacts[i].getField("nickname") << std::endl
		<< "Phone number: " << this->contacts[i].getField("number") << std::endl
		<< "Secret (shh): " << this->contacts[i].getField("secret") << std::endl;
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
			<< std::right << "|" << std::setw(10) << truncate_entry(contacts[i].getField("firstname"))
			<< std::right << "|" << std::setw(10) << truncate_entry(contacts[i].getField("lastname"))
			<< std::right << "|" << std::setw(10) << truncate_entry(contacts[i].getField("nickname"))
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
			if (index.length() > 1 || !isdigit(index.at(0)))
				throw std::invalid_argument("Invalid. Single digit only");
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
