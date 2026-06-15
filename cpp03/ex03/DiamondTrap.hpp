#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	//first scav then frag just like when constructing
	private:
		std::string _Name;
	public:	
		DiamondTrap();
		DiamondTrap(std::string Name);
		DiamondTrap(const DiamondTrap& cpyfrom);
		DiamondTrap& operator=(const DiamondTrap& cpyfrom);
		~DiamondTrap();

		void	whoAmI();
		void	attack(const std::string& target);
		void	showStats(void);
};