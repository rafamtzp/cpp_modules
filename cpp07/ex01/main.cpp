#include "iter.hpp"
#include <iostream>
#include <string>

// int functions
void addone(int& a)
{
	a++;
}

void printIntConst(const int& a)
{
	std::cout << a << " ";
}

// string functions
void appendBang(std::string& s)
{
	s += "!";
}

void printStringConst(const std::string& s)
{
	std::cout << s << " ";
}

int main(void)
{
	std::cout << "--- Testing standard integer array ---" << std::endl;
	int arr[3] = {1, 2, 3};
	iter(arr, 3, addone);
	iter(arr, 3, printIntConst); 
	//iter(arr, 3, 2);
	std::cout << std::endl;

	std::cout << "\n--- Testing CONST integer array ---" << std::endl;
	const int carr[3] = {10, 20, 30};
	//iter(carr, 3, addone);   // compiler error if uncommented
	iter(carr, 3, printIntConst);
	std::cout << std::endl;

	std::cout << "\n--- Testing string array ---" << std::endl;
	std::string sarr[3] = {"Hello", "42", "World"};
	iter(sarr, 3, appendBang);
	iter(sarr, 3, printStringConst);
	std::cout << std::endl;

	return 0;
}
