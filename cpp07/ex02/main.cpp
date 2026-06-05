#include <iostream>
#include <string>
#include <cstdlib>
#include "Array.hpp"

// A simple structure to test complex/custom types if necessary
struct Dummy {
    int x;
    Dummy() : x(42) {} // Default constructor sets x to 42
};

int main() {
    std::cout << "==========================================" << std::endl;
    std::cout << "        TEST 1: Default Constructor        " << std::endl;
    std::cout << "==========================================" << std::endl;
    {
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;
        
        try {
            std::cout << "Attempting to access index 0 of empty array..." << std::endl;
            std::cout << emptyArray[0] << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "    TEST 2: Int Array & Default Init     " << std::endl;
    std::cout << "==========================================" << std::endl;
    {
        unsigned int size = 5;
        Array<int> intArray(size);
        std::cout << "Created int array of size: " << intArray.size() << std::endl;

        // Checking if default initialization to 0 worked
        bool allZeros = true;
        for (unsigned int i = 0; i < intArray.size(); i++) {
            if (intArray[i] != 0) allZeros = false;
        }
        std::cout << "Are all elements default-initialized to 0? " 
                  << (allZeros ? "YES" : "NO (Garbage values detected!)") << std::endl;

        // Modifying elements
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 10;
        }

        std::cout << "Modified array contents: ";
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "    TEST 3: Deep Copy (Copy Constructor)  " << std::endl;
    std::cout << "==========================================" << std::endl;
    {
        Array<std::string> original(3);
        original[0] = "Minitalk";
        original[1] = "Cub3D";
        original[2] = "Inception";

        std::cout << "Original array created." << std::endl;
        
        // Use copy constructor
        Array<std::string> copy(original);
        std::cout << "Copy array created via copy constructor." << std::endl;

        // Modify the copy to verify it's a DEEP copy
        copy[1] = "IRC";
        
        std::cout << "Original[1] (Should be Cub3D): " << original[1] << std::endl;
        std::cout << "Copy[1]     (Should be IRC):   " << copy[1] << std::endl;
        
        if (original[1] != copy[1]) {
            std::cout << ">> SUCCESS: Deep copy verified!" << std::endl;
        } else {
            std::cout << ">> FAIL: Shallow copy detected! Modifying copy altered original." << std::endl;
        }
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "    TEST 4: Deep Copy (Assignment Op)    " << std::endl;
    std::cout << "==========================================" << std::endl;
    {
        Array<int> arr1(3);
        arr1[0] = 1; arr1[1] = 2; arr1[2] = 3;

        Array<int> arr2(5); // Different size
        arr2[0] = 9;

        std::cout << "Before assignment - arr2 size: " << arr2.size() << std::endl;
        
        // Assignment operator
        arr2 = arr1;
        
        std::cout << "After assignment  - arr2 size: " << arr2.size() << std::endl;
        
        // Check deep copy mechanics
        arr2[0] = 99;
        std::cout << "arr1[0] (Should be 1):  " << arr1[0] << std::endl;
        std::cout << "arr2[0] (Should be 99): " << arr2[0] << std::endl;

        // Self-assignment safety check
        std::cout << "Testing self-assignment safety..." << std::endl;
        arr2 = arr2; 
        std::cout << "Self-assignment completed without crashing! arr2[0]: " << arr2[0] << std::endl;
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "         TEST 5: Bounds Checking          " << std::endl;
    std::cout << "==========================================" << std::endl;
    {
        Array<int> arr(4);
        
        try {
            std::cout << "Attempting to access valid index (3)..." << std::endl;
            arr[3] = 42;
            std::cout << "Success! Value is " << arr[3] << std::endl;
            
            std::cout << "Attempting to access out-of-bounds index (4)..." << std::endl;
            arr[4] = 100; // Should throw
            std::cout << "FAIL: This line should not execute!" << std::endl;
        } 
        catch (const std::exception& e) {
            std::cout << "SUCCESS: Caught exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "         TEST 6: Const Array View         " << std::endl;
    std::cout << "==========================================" << std::endl;
    {
        Array<int> normalArray(2);
        normalArray[0] = 24;
        normalArray[1] = 42;

        // Instantiating a const reference to look at our array
        const Array<int>& constArray = normalArray;
        
        std::cout << "Const array size: " << constArray.size() << std::endl;
        std::cout << "Const array elements: " << constArray[0] << " " << constArray[1] << std::endl;
        
        // The following line should fail compilation if uncommented, 
        // confirming that const-correctness is working perfectly:
        // constArray[0] = 12; 
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "     TEST 7: Complex Type Initialization   " << std::endl;
    std::cout << "==========================================" << std::endl;
    {
        Array<Dummy> dummyArray(3);
        std::cout << "Dummy array element default constructor check (Should be 42): " 
                  << dummyArray[1].x << std::endl;
    }

    std::cout << "==========================================" << std::endl;
    return 0;
}