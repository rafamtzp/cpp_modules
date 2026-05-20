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
    }
    std::cout << std::endl;

    // TEST 2: Invalid Instantiations (Constructor Exceptions)
    std::cout << "--- TEST 2: Constructor Boundaries ---" << std::endl;
    
    // Too High
    try
	{
        std::cout << "Attempting to create a bureaucrat with grade 0..." << std::endl;
        Bureaucrat boss("The Boss", 0);
        std::cout << "Success? " << boss << std::endl; // Should not execute
    }
    catch (const std::exception& e)
	{
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Too Low
    try
	{
        std::cout << "Attempting to create a bureaucrat with grade 151..." << std::endl;
        Bureaucrat intern("The Intern", 151);
        std::cout << "Success? " << intern << std::endl; // Should not execute
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
        Bureaucrat highFlyer("High Flyer", 3);
        std::cout << highFlyer << std::endl;
        
        highFlyer.incrementGrade();
        std::cout << "Incremented: " << highFlyer << std::endl;
        
        highFlyer.incrementGrade();
        std::cout << "Incremented: " << highFlyer << std::endl;
        
        std::cout << "Attempting to breach grade 1 limit..." << std::endl;
        highFlyer.incrementGrade();
        std::cout << "Success? " << highFlyer << std::endl;
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
        Bureaucrat slacker("Slacker", 148);
        std::cout << slacker << std::endl;
        
        slacker.decrementGrade();
        std::cout << "Decremented: " << slacker << std::endl;
        
        slacker.decrementGrade();
        std::cout << "Decremented: " << slacker << std::endl;
        
        std::cout << "Attempting to breach grade 150 limit..." << std::endl;
        slacker.decrementGrade();
        std::cout << "Success? " << slacker << std::endl;
    }
    catch (const std::exception& e)
	{
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}