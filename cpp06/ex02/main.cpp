#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base*	generate(void)
{
	int	random = rand() % 3;

	switch(random)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (NULL);
}

void	identify(Base* p)
{
	Base*	arr[3] = {
		dynamic_cast<A*>(p),
		dynamic_cast<B*>(p), 
		dynamic_cast<C*>(p),
	};

	std::cout << "points to type ";
	for (int i = 0; i < 3; i++)
	{
		if (arr[i])
		{
			std::cout << (char)('A' + i) << std::endl;
			return ;
		}
	}
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "references an A" << std::endl;
	}
	catch (std::exception& e){};
	
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "references a B" << std::endl;
	}
	catch (std::exception& e){};
	
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "references a C" << std::endl;
	}
	catch (std::exception& e){};
}

int	main(void)
{
	srand(time(0));

	Base *ptr = generate();
	Base& ref = *ptr;

	std::cout << "ptr ";
	identify(ptr);
	std::cout << "ref ";
	identify(ref);

	delete ptr;
}