#pragma once

#include <iostream>

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

