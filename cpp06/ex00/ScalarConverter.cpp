#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string& literal)
{
	// determine type
	int	len = literal.length();
	e_type type = whichType(literal, len);
	// convert to numerical value
	switch (type) {
		case INVALID:
			std::cout << "Invalid input." << std::endl;
			break;
		case SPECIAL:
			printSpecial(literal);
			break;
		case CHAR:
			printChar(literal, len);
			break;
		case INT:
			printInt(literal);
			break;
		case FLOAT:
			printFloat(literal, len);
			break;
		case DOUBLE:
			printDouble(literal);
			break;
	};
	// use static_cast to convert it to other types and display
}

