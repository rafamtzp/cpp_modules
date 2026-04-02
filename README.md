
# CPP Modules

*This project has been created as part of the 42 curriculum by ramarti2.*

---

## 📖 Description

This repository contains implementations of **C++ Modules** from the 42 curriculum. These modules introduce the fundamentals of **Object-Oriented Programming (OOP)** in C++ and progressively build toward more advanced concepts such as inheritance and polymorphism.

Each module is an independent project with its own exercises and objectives. Together, they form a strong foundation in modern C++ programming practices.

---

## ⚙️ Instructions

### 🛠️ Compilation

Each module contains its own exercises, typically structured with a `Makefile`.

To compile an exercise:

```bash
cd cpp_module_00/ex00
make
```

*(Adjust directory names based on your structure.)*

---

### 🧹 Makefile Rules

```bash
make        # compile
make clean  # remove object files
make fclean # remove objects + executable
make re     # rebuild everything
```

---

## 📦 Project Breakdown

### 🧩 Module 00 — Basics of C++

Introduction to C++ syntax and basic concepts.

#### Concepts:

* Namespaces
* Classes and member functions
* std::string
* I/O streams (`std::cout`, `std::cin`)
* Basic class design

### ▶️ Usage

Run the compiled programs:
##### ex00:
This program turns your message to uppercase.  It was about learning to write to stdout using C++ redirections.

* input: ```./megaphone "your message"```
* output: YOUR MESSAGE

##### ex01:
This program taught me how to create my first classes with attributes and methods to create an interactive phonebook interface where one can add and search for contacts in a table.  It also taught me about C++ error handling (try-catch) and using the iomanip library to display a table properly.

* input: ```./phonebook```
* output: \* An interactive phonebook program where you can add and search for contacts in a table. \*

##### ex02 (bonus):
This program was about recreating the file Account.cpp in order to restore functionality to the class found in Account.hpp so that it prints the messages exactly as in 19920104_091532.log (time stamps shouldn't match).  This gave me a deeper understanding of implementing class methods and introduced me to static methods and attributes. 

* input: ```./test```
* ouput: \* printed logs \*
---

### 🧩 Module 01 — Memory and References

Focus on memory management and references in C++.

#### Concepts:

* Pointers vs references
* Dynamic memory allocation (`new` / `delete`)
* Constructors and destructors
* File streams (`std::ifstream`, `std::ofstream`)

### ▶️ Usage and explanation

##### ex00 and ex01:
These exercises are about learning to use **new** and **delete** to heap-allocate a Zombie object (in newZombie.cpp) and an array of Zombies (zombieHorde.cpp), and how this is different from stack-allocating a Zombie (in randomChump.cpp).

##### ex02, ex03:
These exercises serve to illustrate the difference between an object, a **reference** to an object, and a pointer to an object.  Ex02 is an introduction to see how they work and ex03 puts them into practice inside of two classes HumanA and HumanB.  HumanA always holds a weapon and HumanB does not.  Therefore, HumanA has a reference to a weapon as an attribute and HumanB has a pointer.  This is because references must be initialized and what they reference cannot be changed, whereas what a pointer points to can be changed.

**ex00-ex03 usage:** ```./main```

##### ex04:
This exercise was about working with **input and output file streams** in C++ and **std::string methods** to create a program that creates a copy of a file but with every instance of a string replaced by another string.

** usage: ** ```./main [filename] [string to find] [string to replace]```

##### ex05:
This exercise was about creating a method for the Harl class that uses **pointers to** its other **methods**.  This method accepts a string called "level". e.g. if level = "DEBUG" then Harl::debug() prints a debug message.  If level = "INFO" then Harl::info() prints an info message. etc.

**usage:** ```./main```

##### ex06 (bonus):
This exercise was about learning to use **switch statements** in C++. The program takes one of the levels as a parameter and it displays all messages from this level and above.

levels: "DEBUG" < "INFO" < "WARNING" < "ERROR"

e.g. doing ./harlFilter DEBUG will print all the messages, ./harlFilter WARNING will only print the warning and error messages, etc.

**usage:** ```./harlFilter [LEVEL]```

---

### 🧩 Module 02 — Ad-hoc Polymorphism

Introduction to operator overloading and canonical class form.

#### Concepts:

* Orthodox Canonical Form
* Operator overloading
* Fixed-point numbers
* Copy constructors and assignment operators

### ▶️ Usage and explanation

**usage (for all):** ```./main```

**ex00-ex02** are about slowly constructing a class in **Orthodox Canonical Form** for fixed-point numbers.  You start with the essential **constructors and destructors** and the **assignment operator overload** and then progressively add different constructors, methods, and **operator overloads** to make the class functional.

In **ex03** then puts this class into practice. You are tasked to create a Point class for fixed-point cartesian coordinates, and then you are tasked with creating the bsp function, which takes in 3 Points that form a triangle and a fourth point.  The function returns true if the fourth point lies inside the triangle and false otherwise.

---

### 🧩 Module 03 — Inheritance

Exploration of inheritance and class relationships.

#### Concepts:

* Base and derived classes
* Constructor/destructor chaining
* Method overriding
* Access specifiers (`public`, `protected`, `private`)

---

### 🧩 Module 04 — Polymorphism

Advanced object-oriented programming concepts.

#### Concepts:

* Subtype polymorphism
* Virtual functions
* Abstract classes and interfaces
* Deep vs shallow copies

---

## 🧠 Concepts Learned

Across these modules, the following key C++ concepts were developed:

* Object-Oriented Programming (OOP)
* Encapsulation and abstraction
* Constructors and destructors
* Memory management in C++
* Operator overloading
* Inheritance and polymorphism
* Virtual functions and dynamic binding

---

### Topics Covered

* Classes and objects
* Memory management
* Operator overloading
* Inheritance and polymorphism

### 🤖 Use of AI

AI tools (such as ChatGPT) were used for:

* Clarifying C++ syntax and OOP concepts
* Understanding differences between C and C++
* Assisting in writing clear and structured documentation

All code was written, tested, and validated manually.

---

## 🚀 Final Notes

These modules mark the transition from procedural programming in C to object-oriented programming in C++. They emphasize writing structured, reusable, and maintainable code.

Each module builds upon the previous one, gradually introducing more complex abstractions and design patterns essential for modern software development.

---