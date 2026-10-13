#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong amount of arguments\n";
		return 1;
	}
	
	try
	{
		Bitcoin btc;
		btc.parse_db();
		btc.parse_input(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}