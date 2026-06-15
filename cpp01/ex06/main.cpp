#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "too many args\n";
		return (1);
	}

	Harl		harling_harl;
	std::string	str = argv[1];

	if (str == "DEBUG")
		harling_harl.complain(0);
	else if (str == "INFO")
		harling_harl.complain(1);
	else if (str == "WARNING")
		harling_harl.complain(2);
	else if (str == "ERROR")
		harling_harl.complain(3);
	else
		harling_harl.complain(7);
	return (0);
}