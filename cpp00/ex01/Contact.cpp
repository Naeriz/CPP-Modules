#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}


void	Contact::print_details()
{
	std::cout << "first name: "<< firstn << "\n";
	std::cout << "last name: "<< lastn << "\n";
	std::cout << "nickname: "<< nickn << "\n";
	std::cout << "phone number: "<< phonen << "\n";
	std::cout << "darkest secret: "<< dark_secret << "\n\n";
}

//string& makes it use same memory adress not copy ->more efficient
std::string	Contact::truncater(std::string& str, unsigned int width)
{
	if (str.length() <= width)
		return str;
	return (str.substr(0, width -1) + ".");
}
//substr mods string

void	Contact::print_stuff(int i)
{
	std::string index;
	index[0] = i + 48;

	std::cout << std::right << std::setfill(' ');
	std::cout << std::setw(10) << i + 1 << "|"
			  << std::setw(10) << truncater(firstn, 10) << "|"
			  << std::setw(10) << truncater(lastn, 10) << "|"
			  << std::setw(10) << truncater(nickn, 10) << "|\n";
}

int		Contact::check_digit(std::string phonen) 
{
	int	i = 0;

	if (phonen[i] == '+')
		i++;
	while (phonen[i])
	{
		if (isdigit(phonen[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

//weirdo cuz who puts spaces and unprintable stuff
int		Contact::check_weirdo(std::string str)
{
	int	i = 0;

	while (str[i])
	{
		if (std::isgraph(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	Contact::contact_filler()
{
	std::string input;

	std::cout << "[your answers can only consist of letters (a-z, A-Z), digits (0-9), punctuation (!, @, #, etc.)]\n";
	std::cout << "please enter first name\n";
	std::getline(std::cin, input);
	firstn = input; //no need touch memory with std::string

	std::cout << "please enter last name\n";
	std::getline(std::cin, input);
	lastn = input;

	std::cout << "please enter nickname\n";
	std::getline(std::cin, input);
	nickn = input;

	std::cout << "please enter phonenumber\n";
	std::getline(std::cin, input);
	phonen = input;

	std::cout << "please enter darkest secret\n";
	std::getline(std::cin, input);
	dark_secret = input;

	if (firstn.empty() || lastn.empty() || nickn.empty() || phonen.empty() || dark_secret.empty())
	{
		std::cout << "input cannot be empty\n";
		return (1);
	}
	if (check_digit(phonen))
	{
		std::cout << "only digits allowed for phonenum\n";
		return (1);
	}
	if (check_weirdo(firstn) || check_weirdo(lastn) || check_weirdo(nickn) || check_weirdo(phonen) || check_weirdo(dark_secret))
	{
		std::cout << "your answers can only consist of letters (a-z, A-Z), digits (0-9), punctuation (!, @, #, etc.)\n";
		return (1);
	}
	return (0);
}

