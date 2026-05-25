#include "ScalarConverter.hpp"

static e_type	whichType(const std::string& literal)
{
	float f = ;
	std::cout << f << std::endl;
}

void	ScalarConverter::convert(const std::string& literal)
{
	// determine type
	e_type type = whichType(literal);
	// convert to numerical value

	// use static_cast to convert it to other types and display


}

int main(void)
{
	whichType("a");
}