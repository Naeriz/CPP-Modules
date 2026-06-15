#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hp = 100;
	_energy = 100;
	_ad = 30;
	std::cout << "FragTrap default has been constructed\n";
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
	_hp = 100;
	_energy = 100;
	_ad = 30;
	std::cout << "FragTrap " << Name << " has been constructed\n";
}

FragTrap::FragTrap(const FragTrap& cpyfrom) : ClapTrap(cpyfrom)
{
	std::cout << "FragTrap copy constructor has been called\n";
}

FragTrap	&FragTrap::operator=(const FragTrap& cpyfrom)
{
	if (this != &cpyfrom) //good practise
		ClapTrap::operator=(cpyfrom);
	std::cout << "FragTrap assignment operator has been called\n";
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap has been destructed\n";
}

void	FragTrap::highFivesGuys()
{
	std::cout << "Let's high-five!\n";
}