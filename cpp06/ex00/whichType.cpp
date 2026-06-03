#include <climits>
#include <cerrno>
#include <cstdlib>
#include "ScalarConverter.hpp"


static bool	isSpecial(const std::string& literal)
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

static bool	isChar(const std::string& literal, int len)
{
	if (len == 1 && !std::isdigit(literal[0]))
		return true;
	else if (len == 3 && literal[0] == '\'' && literal[2] == '\'')
		return true;
	return false;
}

static bool	isInt(const std::string& literal)
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

static bool	isFloat(const std::string& literal, int len)
{
	char *endptr;
	errno = 0;
	std::string sub = literal.substr(0, len - 1);
	std::strtod(sub.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0')
		return false;
	return true;
}

static bool	isDouble(const std::string& literal)
{
	char *endptr;
	errno = 0;
	std::strtod(literal.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0')
		return false;
	return true;
}

e_type	whichType(const std::string& literal, int len)
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

