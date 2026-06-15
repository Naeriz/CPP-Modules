#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
	public:
		FragTrap();
		FragTrap(std::string Name);
		FragTrap(const FragTrap& cpyfrom);
		FragTrap& operator=(const FragTrap& cpyfrom);
		~FragTrap();
		void highFivesGuys(void);
};