#include "PmergeMe.hpp"

int	parse_token(const std::string &token)
{
	if (token.empty())
		throw(std::invalid_argument("empty string"));
	if (token.find_first_not_of("0123456789") != std::string::npos)
		throw(std::invalid_argument("only digits accepted"));
	unsigned long value = strtoul(token.c_str(), NULL, 10);
	if (value > INT_MAX)
		throw(std::out_of_range("bigger than int"));
	return(value);
}


int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: no numbers given\n";
		return 1;
	}
	std::vector<int> _input;
	PmergeMe object;
	try
	{
		for (int i = 1; argc > i; i++)
		{
			_input.push_back(parse_token(argv[i])); 
		}
		std::cout << "Before:";
		for (size_t i = 0; i < _input.size(); i++)
			std::cout << " " << _input[i];
		std::cout << std::endl;

		clock_t start = clock(); //cpu time in ticks
		std::vector<int> fillInput(_input.begin(), _input.end()); //only there to make it work same as deq for time

		std::vector<int> _sorted = object.rec_sort_vec(fillInput); //used to be _input

		clock_t end = clock();
		double _vecTime = (end - start) * 1000000.0 / CLOCKS_PER_SEC;

		//deque
		clock_t startD = clock();
		std::deque<int> deqInput(_input.begin(), _input.end());
		std::deque<int> deqSorted = object.rec_sort_deq(deqInput);
		clock_t endD = clock();
		double _deqTime = (endD - startD) * 1000000.0 / CLOCKS_PER_SEC;

		std::cout << "After: ";
		for (size_t i = 0; i < _sorted.size(); i++)
			std::cout << " " << _sorted[i];
		std::cout << std::endl;

		std::cout << std::fixed << std::setprecision(5); //to match subject time format
		std::cout << "Time to process a range of " << _input.size() << " elements with std::vector : " << _vecTime << " us" << std::endl;
		std::cout << "Time to process a range of " << _input.size() << " elements with std::deque  : " << _deqTime << " us" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return (0);
}