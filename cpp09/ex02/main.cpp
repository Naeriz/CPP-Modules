#include <climits>
#include <stdexcept>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

int	parse_token(const std::string &token)
{
	if (token.empty()) //|| token.find_first_not_of(" \t") == std::string::npos)
		throw(std::invalid_argument("empty string"));
	if (token.find_first_not_of("0123456789") != std::string::npos)
		throw(std::invalid_argument("only digits accepted"));
	// if (token.find_first_not_of("-+") == std::string::npos)
	// 	throw(std::invalid_argument("no signs accepted"))
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
	try
	{
		std::vector<int> _input;
		for (int i = 1; argc > i; i++)
		{
			_input.push_back(parse_token(argv[i])); 
		}
		std::cout << "Before:";
		for (size_t i = 0; i < _input.size(); i++)
			std::cout << " " << _input[i];
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return (0);
}