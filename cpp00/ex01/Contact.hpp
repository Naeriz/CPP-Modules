#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class Contact {
private: //only known to contact methods
	std::string firstn;
	std::string lastn;
	std::string nickn;
	std::string phonen;
	std::string dark_secret;
public: //methods r funcs that only class can use //only object of this type can use methods
	Contact();
	~Contact();

	int			contact_filler();
	int			check_digit(std::string phonen);
	int			check_weirdo(std::string str);
	std::string	truncater(std::string& str, unsigned int width);
	void		print_stuff(int i);
	void		print_details();
};

#endif