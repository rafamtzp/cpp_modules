#include "ScalarConverter.hpp"
#include <cerrno>
#include <cstdlib>
#include <climits>

bool	isSpecial(const std::string& literal)
{
	std::string specials[6] = {
		"nan", "nanf",
		"+inf", "-inf",
		"+inff", "-inff"
	};
	for (int i = 0; i < 6; i++)
	{
		if (literal == specials[i])
			return true;
	}
	return false;
}

bool	isChar(const std::string& literal, int len)
{
	if (len == 1 && !std::isdigit(literal[0]))
		return true;
	else if (len == 3 && literal[0] == '\'' && literal[2] == '\'')
		return true;
	return false;
}

bool	isInt(const std::string& literal)
{
	char *endptr;
	errno = 0;
	long value = std::strtol(literal.c_str(), &endptr, 10);
	if (errno == ERANGE || value > INT_MAX || value < INT_MIN)
		return false;
	if (literal.empty() || *endptr != '\0')
		return false;
	return true;
}

bool	isFloat(const std::string& literal, int len)
{
	char *endptr;
	errno = 0;
	std::string sub = literal.substr(0, len - 1);
	std::strtod(sub.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0')
		return false;
	return true;
}

bool	isDouble(const std::string& literal)
{
	char *endptr;
	errno = 0;
	std::strtod(literal.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0')
		return false;
	return true;
}

static e_type	whichType(const std::string& literal, int len)
{
	size_t decimal = literal.find('.');
	size_t f = literal.find('f');

	if (decimal == std::string::npos)
	{
		if (isSpecial(literal))
			return SPECIAL;
		if (isChar(literal, len))
			return CHAR;
		if (isInt(literal))
			return INT;
		return INVALID;
	}
	if (f != std::string::npos)
	{
		if (isFloat(literal, len))
			return FLOAT;
	}
	else
	{
		if (isDouble(literal))
			return DOUBLE;
	}
	return INVALID;
}

void	printSpecial(const std::string& literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	printChar(const std::string& literal, int len)
{
	int i = 0;

	std::cout << "char: ";
	if (len == 1 && std::isprint(literal[0]))
		std::cout << literal[i] << std::endl;
	else if (len == 3 && std::isprint(literal[1]))
		std::cout << literal[++i] << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(literal[i]) << std::endl;
	std::cout << "float: " << static_cast<float>(literal[i]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(literal[i]) << ".0" << std::endl;
}

void	printInt(const std::string& literal)
{
	int value = std::atoi(literal.c_str());
	
	std::cout << "char: ";
	if (value >= 0 && value <= 127)
	{
		if (std::isprint(value))
			std::cout << value << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void	printFloat(const std::string& literal)
{
	char *endptr;

	float value = std::strtof(literal.c_str(), &endptr);
	long	intvalue = std::strtol(literal.c_str(), &endptr, 10);
	float diff = value - intvalue;

	std::cout << "char: ";
	if (diff && intvalue >= 0 && intvalue <= 127)
	{
		if (std::isprint(value))
			std::cout << value << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	
	std::cout << "int: "
	// TODO
	
	<< value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;

	return ;
}

void	printDouble(const std::string& literal)
{
	(void)literal;
	return ;
}

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
			printFloat(literal);
			break;
		case DOUBLE:
			printDouble(literal);
			break;  
	};
	// use static_cast to convert it to other types and display
}

int main(int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid input" << std::endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
}