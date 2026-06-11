#pragma once
#include <stack>

template <typename T>
class MutantStack
{
	private:
	std::stack<T> stack;

	public:
	MutantStack();
	MutantStack(const MutantStack& other);
	~MutantStack();
	MutantStack&	operator=(const MutantStack& other);

	class iterator
	{
		
	};
};