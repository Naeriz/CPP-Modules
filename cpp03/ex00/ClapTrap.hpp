#pragma once

#include <iostream>
#include <string>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAG 	"\033[35m"
#define RESET   "\033[0m"

class ClapTrap{
	private:
		std::string _Name;
		int _hp;
		int	_energy;
		int	_ad;
	public:
		ClapTrap();
		ClapTrap(std::string Name);
		ClapTrap(const ClapTrap& cpyfrom);
		ClapTrap& operator=(const ClapTrap& cpyfrom);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};