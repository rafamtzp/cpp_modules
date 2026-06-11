#pragma once
#include <vector>
#include <exception>

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
	void	addNumber(std::vector<int>::iterator begin, 
					  std::vector<int>::iterator end);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	class SpanFullException : public std::exception {
		virtual const char *what() const throw();
	};
};


