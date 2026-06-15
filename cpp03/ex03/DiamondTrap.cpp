#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap()
{
	_Name = "default";
	_hp = 100;
	_energy = 50;
	_ad = 30;
	std::cout << "DiamondTrap default has been constructed\n";
}

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name + "_clap_name"), ScavTrap(), FragTrap()
{
	_Name = Name;
	_hp = 100;
	_energy = 50;
	_ad = 30;
	std::cout << "DiamondTrap " << Name << " has been constructed\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& cpyfrom) : ClapTrap(cpyfrom), ScavTrap(cpyfrom), FragTrap(cpyfrom)
{
	*this = cpyfrom;
	std::cout << "DiamondTrap copy constructor has been called\n";
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap& cpyfrom)
{
	if (this != &cpyfrom) //good practise
	{
		ClapTrap::operator=(cpyfrom);
		_Name = cpyfrom._Name;
	}
	std::cout << "DiamondTrap assignment operator has been called\n";
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap has been destructed\n";
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << _Name << " but also " << ClapTrap::_Name << "\n";
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::showStats(void)
{
	std::cout << "DiamondTrap ["
	<< this->_Name << "] ["
	<< this->ClapTrap::_Name << "] ["
	<< this->_hp << " HP] ["
	<< this->_energy << " EP] ["
	<< this->_ad << " AD]"
	<< std::endl;
}