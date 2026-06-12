
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "MutantStack.hpp"


void testConstStack(const MutantStack<int>& c_stack) {
    std::cout << "--- Testing Const Iterators ---" << std::endl;
    
    // This must compile using const_iterator
    MutantStack<int>::const_iterator it = c_stack.begin();
    MutantStack<int>::const_iterator ite = c_stack.end();
    
    std::cout << "Const Forward: ";
    while (it != ite) {
        // *it = 42; // should fail to compile! Read-only!
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // This must compile using const_reverse_iterator
    MutantStack<int>::const_reverse_iterator crit = c_stack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = c_stack.rend();
    
    std::cout << "Const Reverse: ";
    while (crit != crite) {
        std::cout << *crit << " ";
        ++crit;
    }
    std::cout << "\n" << std::endl;
}

int main()
{
    // TEST 1: subject tests
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    // TEST 2: Comparing with std::list behavior (as required by subject)
    std::cout << "--- Test 2: Standard List Comparison ---" << std::endl;
    std::list<int> lstack;
    lstack.push_back(5);
    lstack.push_back(17);
    lstack.pop_back();
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    lstack.push_back(0);
    
    std::list<int>::iterator lit = lstack.begin();
    std::list<int>::iterator lite = lstack.end();
    std::cout << "List contents via normal iterator:  ";
    while (lit != lite)
    {
        std::cout << *lit << " ";
        ++lit;
    }
    std::cout << "\n(Outputs from Test 1 and Test 2 should match exactly!)\n" << std::endl;

    // TEST 3: Reverse Iteration & Random Access Skip math
    std::cout << "--- Test 3: Reverse Iteration & Superpowers ---" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    
    std::cout << "Reverse traversal (Top to Bottom): ";
    while (rit != rite)
    {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;

    // Test Random Access Capability (jumping around)
    MutantStack<int>::iterator jumpIt = mstack.begin();
    jumpIt += 3; 
    std::cout << "Random Access jumpIt += 3 (should be 737): " << *jumpIt << std::endl;
    jumpIt -= 2;
    std::cout << "Random Access jumpIt -= 2 (should be 3):   " << *jumpIt << "\n" << std::endl;


    // TEST 4: Const Correctness
    testConstStack(mstack);


    // TEST 5: Orthodox Canonical Form (Copy / Assignment check)
    std::cout << "--- Test 5: OCF / Stack Assignment Conversion ---" << std::endl;
    std::stack<int> s(mstack); // Copying MutantStack into a standard std::stack
    std::cout << "Standard stack size from mutant copy: " << s.size() << std::endl;
    
    MutantStack<int> assignStack;
    assignStack = mstack; // Testing assignment operator
    std::cout << "Assigned mutant stack top: " << assignStack.top() << "\n" << std::endl;


    // TEST 6: Non-default underlying container (std::vector)
    std::cout << "--- Test 6: Underlying Vector Container ---" << std::endl;
    MutantStack<double, std::vector<double>> vecStack;
    vecStack.push(1.1);
    vecStack.push(2.2);
    vecStack.push(3.3);
    
    std::cout << "Vector-backed stack content: ";
    for (MutantStack<double, std::vector<double> >::iterator vit = vecStack.begin(); vit != vecStack.end(); ++vit) {
        std::cout << *vit << " ";
    }
    std::cout << "\n" << std::endl;


    // TEST 7: Compatibility with STL Algorithms (std::sort)
    std::cout << "--- Test 7: Compatibility with std::sort ---" << std::endl;
    // Current mstack state: 5 3 5 737 0
    std::cout << "Before Sorting: ";
    for (MutantStack<int>::iterator sit = mstack.begin(); sit != mstack.end(); ++sit) std::cout << *sit << " ";
    std::cout << std::endl;

    std::sort(mstack.begin(), mstack.end());

    std::cout << "After Sorting:  ";
    for (MutantStack<int>::iterator sit = mstack.begin(); sit != mstack.end(); ++sit) std::cout << *sit << " ";
    std::cout << std::endl;
    return 0;
}