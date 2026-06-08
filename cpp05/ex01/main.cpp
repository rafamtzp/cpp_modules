#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "--- TEST 1: Form Creation & Insertion Operator ---" << std::endl;
	try
	{
		Form f1("Form1", 50, 25);
		std::cout << f1 << std::endl;

		std::cout << "Getters and Setters:" << std::endl;
		std::cout << "getName: " << f1.getName() << std::endl;
		std::cout << "getIsSigned: " << f1.getIsSigned() << std::endl;
		std::cout <<  "getGradeToSign: " << f1.getGradeToSign() << std::endl;
		std::cout << "getGradeToExecute: " << f1.getGradeToExecute() << std::endl;
	}
	catch (std::exception &e) 
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- TEST 2: Form Constructor Exceptions ---" << std::endl;
	try
	{
		std::cout << "Trying to create form with sign grade 0..." << std::endl;
		Form f2("Form2", 0, 50);
	}
	catch (std::exception &e) 
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "Trying to create form with execute grade 151..." << std::endl;
		Form f3("Form3", 50, 151);
	}
	catch (std::exception &e) 
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- TEST 3: Successful Signing ---" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 40);
		Form nda("NDA", 50, 50);

		std::cout << alice << std::endl;
		std::cout << nda << std::endl;
		
		alice.signForm(nda);
		
		std::cout << "After signing attempt:" << std::endl;
		std::cout << nda << std::endl;
	}
	catch (std::exception &e) 
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 4: Failed Signing (Grade too low) ---" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 100);
		Form contract("Contract", 50, 50);

		std::cout << bob << std::endl;
		std::cout << contract << std::endl;
		
		bob.signForm(contract);
		
		std::cout << "After signing attempt:" << std::endl;
		std::cout << contract << std::endl;
	}
	catch (std::exception &e) 
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}