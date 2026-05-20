#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "--- TEST 1: Form Creation & Insertion Operator ---" << std::endl;
    try 
    {
        Form f1("Tax_Return", 50, 25);
        std::cout << f1 << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Form Constructor Exceptions ---" << std::endl;
    try 
    {
        std::cout << "Trying to create form with sign grade 0..." << std::endl;
        Form f2("Top_Secret", 0, 50);
    } 
    catch (std::exception &e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try 
    {
        std::cout << "Trying to create form with execute grade 151..." << std::endl;
        Form f3("Junk_Mail", 50, 151);
    } 
    catch (std::exception &e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: Successful Signing ---" << std::endl;
    try 
    {
        Bureaucrat alice("Alice", 40); // Grade 40
        Form nda("NDA", 50, 50);       // Needs 50 to sign

        std::cout << alice << std::endl;
        std::cout << nda << std::endl;
        
        alice.signForm(nda);           // Should succeed (40 <= 50)
        
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
        Bureaucrat bob("Bob", 100);    // Grade 100
        Form contract("Contract", 50, 50); // Needs 50 to sign

        std::cout << bob << std::endl;
        std::cout << contract << std::endl;
        
        bob.signForm(contract);        // Should fail (100 > 50)
        
        std::cout << "After signing attempt:" << std::endl;
        std::cout << contract << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}