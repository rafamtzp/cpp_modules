#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	// TEST 1: Standard Canonical Form & Normal Operator Overloads
	std::cout << "--- TEST 1: Canonical Form & Operators ---" << std::endl;
	{
		Bureaucrat hermes("Hermes", 42);
		std::cout << "Created: " << hermes << std::endl;

		// Copy Constructor
		Bureaucrat copy(hermes);
		std::cout << "Copy Constructor: " << copy << std::endl;

		// Assignment Operator
		Bureaucrat assigned;
		assigned = hermes;
		std::cout << "Assignment Operator: " << assigned << std::endl;

		// Accessors
		std::cout << "getName: " << hermes.getName() << std::endl;
		std::cout << "getGrade: " << hermes.getGrade() << std::endl;
	}
	std::cout << std::endl;

	// TEST 2: Invalid Instantiations (Constructor Exceptions)
	std::cout << "--- TEST 2: Constructor Boundaries ---" << std::endl;

	// Too High
	try
	{
		std::cout << "Attempting to create a bureaucrat with grade 0..." << std::endl;
		Bureaucrat zeus("Zeus", 0);
		std::cout << "Success? " << zeus << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	// Too Low
	try
	{
		std::cout << "Attempting to create a bureaucrat with grade 151..." << std::endl;
		Bureaucrat poseidon("Poseidon", 151);
		std::cout << "Success? " << poseidon << std::endl;
	} 
	catch (const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// TEST 3: Incrementing Boundaries
	std::cout << "--- TEST 3: Grade Increment Boundaries ---" << std::endl;
	try
	{
		Bureaucrat hades("Hades", 3);
		std::cout << hades << std::endl;

		hades.incrementGrade();
		std::cout << "Incremented: " << hades << std::endl;

		hades.incrementGrade();
		std::cout << "Incremented: " << hades << std::endl;

		std::cout << "Attempting to breach grade 1 limit..." << std::endl;
		hades.incrementGrade();
		std::cout << "Success? " << hades << std::endl;
	} 
	catch (const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// TEST 4: Decrementing Boundaries
	std::cout << "--- TEST 4: Grade Decrement Boundaries ---" << std::endl;
	try
	{
		Bureaucrat hercules("Hercules", 148);
		std::cout << hercules << std::endl;

		hercules.decrementGrade();
		std::cout << "Decremented: " << hercules << std::endl;

		hercules.decrementGrade();
		std::cout << "Decremented: " << hercules << std::endl;

		std::cout << "Attempting to breach grade 150 limit..." << std::endl;
		hercules.decrementGrade();
		std::cout << "Success? " << hercules << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	return 0;
}