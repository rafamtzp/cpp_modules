#include "Span.hpp"
#include <algorithm>

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

const char *Span::SpanFullException::what() const throw()
{
	return ("Span is full");
}

void	Span::addNumber(int n)
{
	if (vec.size() + 1 > N)
		throw SpanFullException();
	vec.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator begin, 
						std::vector<int>::iterator end)
{
	if (vec.size() + std::distance(begin, end) > N)
		throw SpanFullException();
	vec.insert(vec.end(), begin, end);
}

unsigned int	Span::shortestSpan()
{
	std::vector<int> tmp = vec;

	std::sort(tmp.begin(), tmp.end());
	
	std::vector<int> diffs;
	std::vector<int>::iterator it;
	for (it = tmp.begin(); it < (tmp.end() - 1); it++)
		diffs.push_back(*(it + 1) - *it);
	
	return (*std::min_element(diffs.begin(), diffs.end()));
}
unsigned int	Span::longestSpan()
{
	std::vector<int>::iterator min;
	std::vector<int>::iterator max;
	
	min = std::min_element(vec.begin(), vec.end());
	max = std::max_element(vec.begin(), vec.end());

	return (*max - *min);
}