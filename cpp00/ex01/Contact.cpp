#include "Contact.hpp"

Contact::Contact(void)
{
	this->firstname = "";
	this->lastname = "";
	this->nickname = "";
	this->number = "";
	this->secret = "";
	std::cout << "Contact constructor called" << std::endl;
}


Contact::Contact(char *firstname, char *lastname, char *nickname, char *number, char *secret) : 
firstname(firstname), lastname(lastname), nickname(nickname), number(number), secret(secret)
{
	std::cout << "Alt Contact constructor called" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact Destructor called" << std::endl;
}