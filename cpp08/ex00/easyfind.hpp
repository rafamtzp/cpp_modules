#pragma once

#include <exception>

class NotFoundException : public std::exception {
	public:
	virtual const char *what() const throw();
};

#include "easyfind.tpp"
