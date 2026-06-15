#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(std::string Name);
		ScavTrap(const ScavTrap& cpyfrom);
		ScavTrap& operator=(const ScavTrap& cpyfrom);
		~ScavTrap();
		
		void guardGate();
		void attack(const std::string& target);
};