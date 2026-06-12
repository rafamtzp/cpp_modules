#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>


int main()
{
    std::srand(std::time(NULL));

	std::cout << "Test 1: Subject" << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

    std::cout << "\nTest 2: Edge Cases (Exceptions)" << std::endl;
    {
        Span sp(5);
        
        try 
		{
            std::cout << "Testing shortestSpan on empty..." << std::endl;
            sp.shortestSpan();
        } 
		catch (const std::exception& e)
		{
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }

        try
		{
            sp.addNumber(42);
            std::cout << "Testing longestSpan with 1 element..." << std::endl;
            sp.longestSpan();
        }
		catch (const std::exception& e)
		{
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }
    }

   	std::cout << "\nTest 3: Filling Past Capacity Exception" << std::endl;
    {
        Span sp(2);
        try
		{
            sp.addNumber(1);
            sp.addNumber(2);
            std::cout << "Attempting to add a 3rd number to a Span of size 2..." << std::endl;
            sp.addNumber(3);
        }
		catch (const std::exception& e)
		{
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }
    }

	std::cout << "\nTest 4: Negative Numbers & Duplicates" << std::endl;;
    {
        Span sp(4);
        sp.addNumber(-10);
        sp.addNumber(-20);
        sp.addNumber(10);
        sp.addNumber(-10); // Duplicate

        std::cout << "Shortest span (between -10 and -10): " << sp.shortestSpan() << " (Expected: 0)" << std::endl;
        std::cout << "Longest span (between -20 and 10):   " << sp.longestSpan() << " (Expected: 30)" << std::endl;
    }

	std::cout << "\nTest 5: Range of Iterators (15,000+ elements)" << std::endl;
    {
        int size = 15000;
        Span sp(size);
        std::vector<int> numbers;

        for (int i = 0; i < size; ++i)
            numbers.push_back(i * 10);

        try
		{
            std::cout << "Inserting " << size << " elements via iterator range..." << std::endl;
            sp.addNumber(numbers.begin(), numbers.end());
            
            std::cout << "Shortest span: " << sp.shortestSpan() << " (Expected: 10)" << std::endl;
            std::cout << "Longest span:  " << sp.longestSpan() << " (Expected: " << (size - 1) * 10 << ")" << std::endl;
        }
		catch (const std::exception& e)
		{
            std::cout << "Error: Range insertion failed! " << e.what() << std::endl;
        }
    }

	std::cout << "\nTest 6: Range Insertion Overflow Guard" << std::endl;;
    {
        Span sp(5);
        std::vector<int> numbers(10, 42);

        try
		{
            std::cout << "Attempting to insert a vector of size 10 into a Span of size 5..." << std::endl;
            sp.addNumber(numbers.begin(), numbers.end());
            std::cout << "Failure: Span allowed overflow!" << std::endl;
        }
		catch (const std::exception& e)
		{
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }
    }
    return 0;
}