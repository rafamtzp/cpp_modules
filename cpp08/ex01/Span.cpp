#include "Span.hpp"

Span::Span() {}
Span::Span(unsigned int N): N(N) {}
Span::Span(const Span& other): vec(other.vec), N(other.N) {}
Span::~Span() {}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		vec = other.vec;
		N = other.N;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	vec.push_back(n);
}

unsigned int	Span::shortestSpan() {}
unsigned int	Span::longestSpan() {}