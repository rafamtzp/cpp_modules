#include <cerrno>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iostream>

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
		std::cout << "'" << literal[i] << "'" << std::endl;
	else if (len == 3 && std::isprint(literal[1]))
		std::cout << "'" << literal[++i] << "'" << std::endl;
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
			std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void	printFloat(const std::string& literal, int len)
{
	char *endptr;

	std::string sub = literal.substr(0, len - 1);
	double value = std::strtod(sub.c_str(), &endptr);

	std::cout << "char: ";
	if (value >= 0 && value <= 127)
	{
		if (std::isprint(value))
			std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	
	std::cout << "int: ";
	if (value <= INT_MAX && value >= INT_MIN)
		std::cout << static_cast<int>(value) << std::endl;
	else
		std::cout << "impossible" << std::endl;

	//float and double:
	if ((std::abs(value) > 1e6f || (value != 0 && std::abs(value) < 1e-4f)) 
	|| (std::floor(value) != value))
	{
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	}
	else if (std::floor(value) == value)
	{
		std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
	}
	return ;
}

void	printDouble(const std::string& literal)
{
	char *endptr;

	double value = std::strtod(literal.c_str(), &endptr);

	std::cout << "char: ";
	if (value >= 0 && value <= 127)
	{
		if (std::isprint(value))
			std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	
	std::cout << "int: ";
	if (value <= INT_MAX && value >= INT_MIN)
		std::cout << static_cast<int>(value) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	
	//float and double:
	if ((std::abs(value) > 1e6f || (value != 0 && std::abs(value) < 1e-4f)) || (std::floor(value) != value))
	{
		if (value <= __FLT_MAX__ && value >= -__FLT_MAX__)
			std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		else
			std::cout << "float: impossible" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	}
	else if (std::floor(value) == value)
	{
		if (value <= __FLT_MAX__ && value >= -__FLT_MAX__)
			std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
		else
			std::cout << "float: impossible" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
	}
	return ;
}
