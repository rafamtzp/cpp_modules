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
	if (this->firstname.empty() || this->lastname.empty() ||
		this->nickname.empty() || this->number.empty() || this->secret.empty())
		return false;
	return true;
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

bool	Contact::setField(std::string field, std::string input)
{
	bool is_valid = false;

	for (int i = 0; i < input.length() && !is_valid; i++) //check nonempty
	{
		if (isascii(input[i]) && !isspace(input[i]))
			is_valid = true;
	}
	for (int i = 0; i < input.length() && is_valid; i++) // check all ascii
	{
		if (!isascii(input[i]))
			is_valid = false;
	}
	if (is_valid == true)
	{
		if (field == "firstname")
			firstname = input;
		else if (field == "lastname")
			lastname = input;
		else if (field == "nickname")
			nickname = input;
		else if (field == "number")
			number = input;
		else if (field == "secret")
			secret = input;
	}
	return (is_valid);
}

std::string	Contact::getField(std::string field)
{
	if (field == "firstname")
		return firstname;
	else if (field == "lastname")
		return lastname;
	else if (field == "nickname")
		return nickname;
	else if (field == "number")
		return number;
	return secret;
}
