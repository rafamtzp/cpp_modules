#pragma once

#include <iostream>
#include <limits>

enum e_type
{
	SPECIAL = 0,
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4,
	INVALID = -1
};

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);

	public:
	static void convert(const std::string& literal);
};

void	printSpecial(const std::string& literal);
void	printChar(const std::string& literal, int len);
void	printInt(const std::string& literal);
void	printFloat(const std::string& literal, int len);
void	printDouble(const std::string& literal);
e_type	whichType(const std::string& literal, int len);
