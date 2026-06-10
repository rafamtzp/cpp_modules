#pragma once
#include <vector>

class	Span
{
	private:
	std::vector<int>	vec;
	unsigned int	N;

	public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span&	operator=(const Span& other);
	~Span();

	void	addNumber(int n);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
};


