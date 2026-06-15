#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <climits>

class	Span
{
private:
	unsigned int		N;
	std::vector<int>	v;

public:
	Span();
	Span(unsigned int);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void	addNumber(int n);
	void	addNumber(unsigned int size, size_t max);
	int		shortestSpan();
	int		longestSpan();
};

