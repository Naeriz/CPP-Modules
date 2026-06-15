
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): cur_index(0), oldest_index(0), counter(0) {} //contructor to set values for when create object

PhoneBook::~PhoneBook() {} //destructor


void	PhoneBook::search()
{
	int i = 0;
	int	input;
	std::string receive;

	std::cout << std::right << std::setfill(' '); //iomanips
	std::cout << std::setw(10) << "index" << "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nickname" << "|\n";
	while (i < 8)
	{
		contacts[i].print_stuff(i);
		i++;
	}
	std::cout << "which contact would you like to view?\n";
	std::cin >> receive;
	if (receive.length() > 1)
		input = 9;
	else
		input = std::atoi(receive.c_str());
	std::cin.ignore(); //to empty buffer so no double "enter cmd pls"
	if (input >= 1 && input <= 8)
	{
		if (input > counter)
			std::cout << "contact " << input << " doesn't exist yet\n";
		else
			contacts[input - 1].print_details();
	}
	else
		std::cout << "please retry with valid index\n";
}

void	PhoneBook::add()
{
	Contact new_con;
	if (new_con.contact_filler() == 1)
	{
		std::cout << "bad input please retry\n";
		return ;
	}
	else
	{
		if (cur_index < 8)
		{
			contacts[cur_index] = new_con;
			cur_index++;
			counter++;
		}
		else if (cur_index == 8)
		{
			cur_index = 0;
			contacts[cur_index] = new_con;
			oldest_index = (oldest_index + 1) % 8;
			cur_index = (cur_index + 1) % 8;
		}
		std::cout << "contact added successfully\n\n";
	}
}

