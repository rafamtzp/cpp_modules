
#include <iostream>

int main( void )
{
	std::string str("HI THIS IS BRAIN");
	std::string *stringPTR = &str;
	std::string& stringREF = str;

	std::cout
	<< "Address of str: " << &str << std::endl
	<< "Address held by stringPTR: " << stringPTR << std::endl
	<< "Address of stringREF: " << &stringREF << std::endl
	<< "Value of str: " << str << std::endl
	<< "Value pointed to by stringPTR: " << *stringPTR << std::endl
	<< "Value of stringREF: " << stringREF << std::endl;
}