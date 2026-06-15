#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	public:
		FragTrap();
		FragTrap(std::string _Name);
		FragTrap(const FragTrap& cpyfrom);
		FragTrap& operator=(const FragTrap& cpyfrom);
		~FragTrap();
		void highFivesGuys(void);
};