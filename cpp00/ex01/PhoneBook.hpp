#ifndef	PHONEBOOK_HPP
#define	PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact	contacts[8]; //in declaration 8 when use 0-7
	int		cur_index;
	int		oldest_index;
	int		counter;

public:
	PhoneBook();
	~PhoneBook();

	void	add();
	void	search();
};

#endif