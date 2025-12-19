#include "Contact.hpp"

Contact::Contact(void)
{
	this->firstname = "";
	this->lastname = "";
	this->nickname = "";
	this->number = "";
	this->secret = "";
	//std::cout << "Contact constructor called" << std::endl;
	return ;
}

bool Contact::has_data(void) const
{
	if (!this->firstname.empty() || !this->lastname.empty() ||
		!this->nickname.empty() || !this->number.empty() || !this->secret.empty())
		return true;
	return false;
}

void Contact::clear(void)
{
	this->firstname = "";
	this->lastname = "";
	this->nickname = "";
	this->number = "";
	this->secret = "";
	return ;
}
Contact::Contact(char *firstname, char *lastname, char *nickname, char *number, char *secret) : 
firstname(firstname), lastname(lastname), nickname(nickname), number(number), secret(secret)
{
	//std::cout << "Alt Contact constructor called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	//std::cout << "Contact Destructor called" << std::endl;
	return ;
}