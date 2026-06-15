#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook book;//create object
	std::string input;

	while (true)
	{
		std::cout << "enter command please\n";
		std::getline(std::cin, input);

		if (std::cin.eof())
		{
			std:: cout << "pressed ctrl+D, exiting now\n";
			exit(0);
		}
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			book.add();//using object to go to method
		else if (input == "SEARCH")
			book.search();
		else if (input.empty())
			continue;
		else
			std::cout << "please retry with 'ADD', 'SEARCH' OR 'EXIT'\n";
	}
	return (0);
}