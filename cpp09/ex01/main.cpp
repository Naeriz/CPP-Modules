#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong amount of arguments\n";
		return (1);
	}

	try
	{
		RPN rpn;
		rpn.token_extract(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}