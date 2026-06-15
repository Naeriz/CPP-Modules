#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span &other) : N(other.N), v(other.v) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N = other.N;
		v = other.v;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int n)
{
	if (N == 0)
		throw(std::logic_error("Impossible to add numbers with a limit of 0"));
	if (v.size() >= N)
		throw(std::logic_error("The vector is already full"));
	v.push_back(n);
}

void	Span::addNumber(unsigned int n, size_t max)
{
	srand(time(NULL));
	unsigned int i = 0;
	int random;

	while (i < n)
	{
		try
		{
			random = rand() % (max + 1);
			addNumber(random);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			break ;
		}
		i++;
	}
}

int		Span::shortestSpan()
{
	if (v.size() < 2)
		throw(std::logic_error("Not enough numbers to find the shortest span"));

	std::vector<int>	v_copy = v;
	std::sort(v_copy.begin(), v_copy.end());
	unsigned int i = 0;
	int shortest = INT_MAX;

	while (i + 1 < v_copy.size())
	{
		if (shortest > (v_copy[i + 1] - v_copy[i]))
			shortest = v_copy[i + 1] - v_copy[i];
		i++;
	}
	return (shortest);
}

int		Span::longestSpan()
{
	if (v.size() < 2)
		throw(std::logic_error("Not enough numbers to find the longest span"));
	return (*std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end()));
}