#pragma once
#include <stack>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
	public:
	MutantStack();
	MutantStack(const MutantStack& other);
	~MutantStack();
	MutantStack<T,C>&	operator=(const MutantStack& other);
	
	typedef typename std::stack<T,C>::container_type::iterator iterator;
	typedef typename std::stack<T,C>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T,C>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T,C>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator	begin();
	const_iterator	begin() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;

	iterator	end();
	const_iterator	end() const;
	reverse_iterator	rend();
	const_reverse_iterator	rend() const;
};

#include "MutantStack.tpp"
